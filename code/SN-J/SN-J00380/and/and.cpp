#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,x,ans;
priority_queue<int> que;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		que.push(x);
	}
	ans=que.top();
	que.pop();
	for(int i=2;i<=m;i++){
		int head=que.top();
		que.pop();
		ans=ans&head;
	}
	cout<<ans;
	return 0;
}
