#include <bits/stdc++.h>
using namespace std;
int sortest=INT_MAX;
vector<int> line[1000];
void dfs(int begin,int index) {
	for (int i=begin;i<a[index].size();i++) {
		dfs(a[index][i]);
	}
}
int main() {
	
}
