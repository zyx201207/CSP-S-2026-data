#include<cstdio>
#include<iostream>
using namespace std;
const int M=2e5+5,B=30;
int n,m,a[M],ans;
bool vis[M];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=B-1;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if((!vis[i])&&((a[i]>>k)&1))cnt++;
		ans<<=1;
		if(cnt<m)continue;
		ans|=1;
		for(int i=1;i<=n;i++)
			if(!((a[i]>>k)&1))vis[i]=true;
	}
	cout<<ans;
}
