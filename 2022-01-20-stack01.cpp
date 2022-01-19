#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> day;

    int size = progresses.size();
    int restDay, x, now;

    for (int i = size - 1; i >= 0; i--) {
        restDay = (100 - progresses[i]) / speeds[i];
        if (((100 - progresses[i]) % speeds[i]) != 0) (restDay)++;
        day.push(restDay);
    }

    while (!day.empty()) {
        now = day.top();
        x = 0;
        day.pop();
        x++;

        if (day.empty()) answer.push_back(x); break;
        
        while (day.top() - now <= 0) {
            day.pop();
            x++;
            if (day.empty()) break;
        }

        answer.push_back(x);
    }

    return answer;
}
