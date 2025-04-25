#include "midterm.h"
#include <iostream>
#include <vector>
#include <algorithm>

// ���ڿ��� ���� ���� Ȯ���ϴ� �Լ�
bool Number(const std::string& str) {
    if (str.empty())
        return false;

    for (char ch : str) {
        if (!isdigit(ch))
            return false;
    }

    return true;
}

// ���� ������ �Է� �޴� �Լ�
std::vector<int> Scores() {
    // ���� ���� ����
    std::vector<int> scores;
    std::string input;

    std::cout << "���� ������ �ϳ��� �Է��ϼ��� (���ڰ� �ƴ� ���� �Է��ϸ� ����):\n";

    // �Է��� �ϳ��� ���� ������ ó��
    std::getline(std::cin, input);  // �� �� �Է� �ޱ�

    size_t pos = 0;
    std::string token;

    // ������ �������� ������ ���� �� �Է� ����
    while ((pos = input.find(' ')) != std::string::npos) {
        token = input.substr(0, pos);
        if (Number(token)) {
            scores.push_back(std::stoi(token));
        }
        else {
            break;  // ���ڰ� �ƴ� �Է��� ������ ����
        }
        input.erase(0, pos + 1);  // ������ �������� �߶� �κ� ����
    }

    // ������ ���� �κ��� ������ �� �����Ƿ� ó��
    if (Number(input)) {
        scores.push_back(std::stoi(input));
    }

    return scores;  // �Է¹��� ���� ���� ��ȯ
}

// ���� ��� ���
double Average(const std::vector<int>& scores) {
    if (scores.empty()) return 0.0;  // ������ ������ ��� 0

    int sum = 0;
    for (int score : scores) sum += score;  // �� ���� ���ϱ�

    // ��� ��� �� ��ȯ
    return static_cast<double>(sum) / scores.size();
}

// �̸��� ���ĺ� ������ �����ϴ� �Լ�
void Name(std::vector<Student>& students) {
    // std::sort �� ������ ��ҵ��� �����ϴ� �Լ�
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        // �л��� �̸��� ���Ͽ� ���ĺ� ������ ����
        // ex) Alex�� Bob �̸�  A�� Alex�� ���� ��
        return a.name < b.name;
        });
}

// ���� ��� �Լ�
void Print(const std::vector<Student>& students) {
    std::cout << "\n--- ���� ��� (�̸� �� ����) ---\n\n";
    for (const auto& student : students) {
        std::cout << student.name << ": " << student.average << "\n";
    }
}