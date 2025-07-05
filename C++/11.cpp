#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct WeatherData {
    double temperature;
    double humidity;
    double pressure;
    double precipitation;
    double windSpeed;
};

vector<WeatherData> readWeatherData(const string& filename) {
    ifstream file(filename);
    vector<WeatherData> data;
    WeatherData entry;

    while (file >> entry.temperature >> entry.humidity 
                >> entry.pressure >> entry.precipitation >> entry.windSpeed) {
        data.push_back(entry);
    }

    return data;
}

void compareForecast(const string& forecastFile, const string& actualFile, const string& resultFile) {
    vector<WeatherData> forecast = readWeatherData(forecastFile);
    vector<WeatherData> actual = readWeatherData(actualFile);

    if (forecast.size() != actual.size()) {
        cerr << "Ошибка: количество записей в файлах не совпадает!" << endl;
        return;
    }

    ofstream result(resultFile);
    result << "День\tОшибка температуры\tОшибка влажности\tОшибка давления\tОшибка осадков\tОшибка ветра\n";

    for (size_t i = 0; i < forecast.size(); ++i) {
        double tempError = abs(forecast[i].temperature - actual[i].temperature);
        double humError = abs(forecast[i].humidity - actual[i].humidity);
        double presError = abs(forecast[i].pressure - actual[i].pressure);
        double precError = abs(forecast[i].precipitation - actual[i].precipitation);
        double windError = abs(forecast[i].windSpeed - actual[i].windSpeed);

        result << i + 1 << "\t" << tempError << "\t" << humError << "\t" 
               << presError << "\t" << precError << "\t" << windError << "\n";
    }

    cout << "Анализ завершен. Результаты сохранены в " << resultFile << endl;
}

int main() {
    compareForecast("forecast.txt", "actual.txt", "errors.txt");
    return 0;
}