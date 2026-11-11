//曲江第一学校  孙辰熙 SN-j01051
#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,m;
queue<long long>q;
stack<long long>s;
int a;
char b;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; ++i) {
		cin>>a>>b;
		m=a;
		for(int j=0; j<a; ++j) {
			q.push(int(b));
			s.push(int(b));
		}
	}
	for(int i=0; i<m/2; ++i) {
		if(q.front()!=s.top()) {
			++sum;
			q.pop();
			s.pop();
		}
	}
	cout<<sum;
	return 0;
}
