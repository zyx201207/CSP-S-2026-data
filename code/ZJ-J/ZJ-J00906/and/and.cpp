#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010][40];//1是最低位 
int c[200010];//指针 
int lac[200010]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int v=a[i];
		int u=1;
		while(v){
			b[i][u++]=v%2;
			v/=2;
		}
		c[i]=i+1;
		lac[i]=i-1;
	}
	c[0]=1;
	lac[n+1]=n;
	long long ans=0;
	for(int i=32;i>=1;i--){
		int noww=0;
		int ss=0;
		while(noww<n+1){
			if(b[noww][i]==1)ss++;
			noww=c[noww];
		}
		if(ss>=m){
			ans=ans+(1<<(i-1));
			noww=0;
			while(noww<n+1){
				if(b[noww][i]==0){
					c[lac[noww]]=c[noww];
					lac[c[noww]]=lac[noww];
				}	
				noww=c[noww];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
