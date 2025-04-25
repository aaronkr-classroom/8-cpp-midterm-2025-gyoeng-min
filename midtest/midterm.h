#pragma once
#ifndef MIDTERM_H
#define MIDTERM_H

#include <string>
#include <vector>

// �л� ���� ���� ����ü
struct Student {
    std::string name;    // �̸�
    std::vector<int> scores; // ���� ����
    double average;      // ���� ���
};

// ���ڷθ� �̷���� �ִ��� Ȯ��
bool Number(const std::string& str);

// ���� ������ �Է� �޴� �Լ�
std::vector<int> Scores();

// ���� ��� ��� �Լ�
double Average(const std::vector<int>& scores);

// �̸��� ���ĺ� ������ �����ϴ� �Լ�
void Name(std::vector<Student>& students);

// ���� ��� �Լ�
void Print(const std::vector<Student>& students);

#endif 