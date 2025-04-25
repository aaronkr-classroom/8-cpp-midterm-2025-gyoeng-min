#include "midterm.h"
#include <iostream>
#include <vector>

int main() {
    int studentCount = 0;
    std::vector<Student> students;

    std::cout << "학생 수를 입력하세요: ";
    std::string input;
    std::getline(std::cin, input);

    // std::getline 줄이 입력을 s.name에 저장하고,
    // 공백이 포함된 이름도 받을 수 있게 함.
    // 예를 들어 gyeong min을 못읽고 gyeong만 읽었지만 min까지 읽게해줌 

    if (!input.empty() && Number(input)) {
        studentCount = std::stoi(input);  // 문자열을 정수로 변환하여 studentCount에 저장
    }

    // 성적 계산
    for (int i = 0; i < studentCount; ++i) {
        std::cout << "\n== 학생 " << (i + 1) << " ==\n";
        Student s;

        // 이름 입력받기
        std::cout << "이름을 입력하세요: ";
        std::getline(std::cin, s.name);

        s.scores = Scores();  // 점수 입력받기
        s.average = Average(s.scores);  // 평균 계산 후 저장

        students.push_back(s);  // 벡터에 학생 객체 추가
    }

    // 이름 순으로 정렬
    Name(students);

    // 정렬된 학생 리스트 출력
    Print(students);

    return 0;
}