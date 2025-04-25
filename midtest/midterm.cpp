#include "midterm.h"
#include <iostream>
#include <vector>
#include <algorithm>

// 문자열이 숫자 인지 확인하는 함수
bool Number(const std::string& str) {
    if (str.empty())
        return false;

    for (char ch : str) {
        if (!isdigit(ch))
            return false;
    }

    return true;
}

// 과제 점수를 입력 받는 함수
std::vector<int> Scores() {
    // 점수 저장 백터
    std::vector<int> scores;
    std::string input;

    std::cout << "과제 점수를 하나씩 입력하세요 (숫자가 아닌 값을 입력하면 종료):\n";

    // 입력을 하나씩 받을 때마다 처리
    std::getline(std::cin, input);  // 한 줄 입력 받기

    size_t pos = 0;
    std::string token;

    // 공백을 기준으로 점수를 여러 개 입력 받음
    while ((pos = input.find(' ')) != std::string::npos) {
        token = input.substr(0, pos);
        if (Number(token)) {
            scores.push_back(std::stoi(token));
        }
        else {
            break;  // 숫자가 아닌 입력이 있으면 종료
        }
        input.erase(0, pos + 1);  // 공백을 기준으로 잘라낸 부분 제거
    }

    // 마지막 남은 부분이 점수일 수 있으므로 처리
    if (Number(input)) {
        scores.push_back(std::stoi(input));
    }

    return scores;  // 입력받은 점수 벡터 반환
}

// 점수 평균 계산
double Average(const std::vector<int>& scores) {
    if (scores.empty()) return 0.0;  // 점수가 없으면 평균 0

    int sum = 0;
    for (int score : scores) sum += score;  // 각 점수 더하기

    // 평균 계산 후 반환
    return static_cast<double>(sum) / scores.size();
}

// 이름을 알파벳 순으로 정렬하는 함수
void Name(std::vector<Student>& students) {
    // std::sort 는 벡터의 요소들을 정렬하는 함수
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        // 학생의 이름을 비교하여 알파벳 순으로 정렬
        // ex) Alex와 Bob 이면  A인 Alex가 먼저 옴
        return a.name < b.name;
        });
}

// 최종 출력 함수
void Print(const std::vector<Student>& students) {
    std::cout << "\n--- 성적 요약 (이름 순 정렬) ---\n\n";
    for (const auto& student : students) {
        std::cout << student.name << ": " << student.average << "\n";
    }
}