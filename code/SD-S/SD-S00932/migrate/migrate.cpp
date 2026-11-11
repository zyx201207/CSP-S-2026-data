#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,D;
long long x[2001000],d[2001000];
int cnt=0,cd=1e9;
void dfs(int wz,int mb,int sl){
//	cout<<wz<<" "<<mb<<"\n";
	if(wz==mb){
		if(cd==sl){
			cnt++;
		}
		else{
			if(cd>sl){
				cd=sl;
				cnt=1;
			}
		}
		return ;
	}
	for(int i=wz+1;i<=mb;i++){
		if(x[i]-x[wz]<=D){
			if(i-wz>=3)return ;
			dfs(i,mb,sl+1);
			
		}
		else{
			break;
		}
	}
}
int check(int l,int r){
	cnt=0;
	cd=1e9;
	dfs(l,r,0);
	if(cnt==2){
		
		return 1;
	}
//	cout<<l<<" "<<r<<" "<<cnt<<"\n";
	return 0;
}
long long ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ans+=check(i,j)==1;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/



