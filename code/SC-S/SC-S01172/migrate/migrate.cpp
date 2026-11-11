#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int m[10000][10000];
int n,d,c,t;

int num=0;
int find(int i,int j,int d,int mi,int ti){
	if(i==j){
		num+=1;
	}
	if(ti<mi){
		for(int o=1;o<=n;o++){
			if(m[i][o]<=d){
				find(o,j,d,mi,ti+1);
			}
		}
	}
	return 0;
}
int mi(int i,int j,int ans){
	int an=i;
	for(int o=i+1;o<=j;o++){
		if(m[i][o]<=d){
			an=o;
		}
	}
	ans++;
	if(an==j){
		return ans;
	}else{
		return mi(an,j,ans);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int x[10000];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				m[i][j]=abs(x[i]-x[j]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				find(i,j,d,mi(i,j,0),0);
				if(num==2){
					ans++;
				}
				num=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}