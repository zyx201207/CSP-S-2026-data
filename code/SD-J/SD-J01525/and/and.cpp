#include<bits/stdc++.h>
using namespace std;
int n,m;
long long v[200005];
int w[200005];
long long dp[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>v[i];
	}
	long long maxx=-0x3f3f3f3f3f3f3f3f;
	if (m==2){
		int front=1,rear=n;
		while (front<rear){
			maxx=max(maxx,v[front]&v[rear]);
			rear--;
			if (rear==front+1){
				front++;
				rear=n;
			}
		}
		cout<<maxx;
	}else if(m==1){
		for (int i=1;i<=n;i++){
			maxx=max(maxx,v[i]);
		}
		cout<<maxx;
	}else{
		sort(v+1,v+n+1,cmp);
		maxx=v[1];
		for (int i=2;i<=m;i++){
			maxx&=v[i];
		}
		cout<<maxx;
	}
	return 0;
}
