#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0; // 현재 location의 문서가 인쇄되는 순서

	int size = priorities.size();
	queue<pair<int,int>> q;
	int max(-1);

	for (int i = 0; i < size; i++) {
		q.push(pair<int,int>(priorities[i],i));
		if (max < priorities[i]) max = priorities[i];
	}

	int order(1);
	while (!q.empty()) {

		pair<int, int> now = q.front();
		q.pop();
        
		if (max > now.first) q.push(now);
		else { 
			if (location == now.second) { 
				answer = order;
				break;
			}
			priorities[now.second] = 0;
			max = -1;
			for (int i = 0; i < size; i++) {
				if (max < priorities[i]) max = priorities[i];
			}
      order++;
		}
	}
	return answer;
}
