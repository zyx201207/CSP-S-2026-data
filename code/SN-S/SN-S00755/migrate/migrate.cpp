#include<bits/stdc++.h>
using namespace std;
int n,d,x[2000005];
bool check(int a,int  b){
	for(int i = a;i<=b;i++){
		if(abs(x[i-1]-x[i])>d)return false;
	}
	return true;
}
int dfs(int a,int b){
	int cnt = 0;
	for(int i = a+1;i<=b-1;i++){
		if(abs(x[b]-x[i])<=d&&abs(x[i]-x[a])<=d){
			cnt++;
		}
	}
	if(abs(x[b]-x[a])<=d&&cnt>=1)cnt==0;
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cha = 1;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(check(i,j)){
					if(dfs(i,j)==2){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
