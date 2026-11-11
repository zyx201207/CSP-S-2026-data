#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#define int long long
using namespace std;

const int MAXN=1e6+5;
int x[MAXN];
int dis(int i,int j){
	return (int)abs(i-j);
}
bool judge(int i,int j,int d){
	return dis(i,j)<=d;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		int minn=1e6;int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dis(i,j)<minn)minn=dis(i,j);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dis(i,j)==minn)cnt++;
			}
		}printf("%lld",cnt);
	}
	return 0;
}
