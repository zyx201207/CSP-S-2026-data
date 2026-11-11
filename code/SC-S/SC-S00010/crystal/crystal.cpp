//1~9样例朴素做法
//骗你的，3000都过不了
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,isdc=1,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=4;i<=n;i++){
		if(a[2]-a[1]!=a[3]-a[2]){
			isdc=0;
			break;
		}
		c=a[2]-a[1];
		if(a[i]-a[i-1]!=c) isdc=0;
	}
	int ans=0;
	if(isdc){
		ans=1;
		int f=m/c;
		int i=1;
		while(f>0){
			if(f-i>=0){
				f-=i;
				ans++;
			}else{
				break;
			}
			i++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=1;
		priority_queue<int> todo;//待选列表
		for(int j=1;j<=n;j++){
			if(i==j||a[j]>a[i]) continue;
			todo.push(a[j]);
		}
//		priority_queue<int> q=todo;
//		cout<<a[i]<<"的可选名单：";
//		while(!q.empty()){
//			cout<<q.top()<<" ";
//			q.pop();
//		}
//		cout<<"\n";
		int t=m;
		while(!todo.empty()){
			if(t-(a[i]-todo.top())>=0){
				sum++;
				t-=(a[i]-todo.top());
			}
			todo.pop();
			if(t<=0) break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}