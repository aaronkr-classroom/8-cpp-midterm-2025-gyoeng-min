#pragma once
#ifndef MIDTERM_H
#define MIDTERM_H

#include <string>
#include <vector>

// 학생 정보 저장 구조체
struct Student {
    std::string name;    // 이름
    std::vector<int> scores; // 점수 저장
    double average;      // 점수 평균
};

// 숫자로만 이루어져 있는지 확인
bool Number(const std::string& str);

// 과제 점수를 입력 받는 함수
std::vector<int> Scores();

// 점수 평균 계산 함수
double Average(const std::vector<int>& scores);

// 이름을 알파벳 순으로 정렬하는 함수
void Name(std::vector<Student>& students);

// 최종 출력 함수
void Print(const std::vector<Student>& students);

#endif 