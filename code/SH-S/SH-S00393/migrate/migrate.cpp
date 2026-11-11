#include<bits/stdc++.h>
using namespace std;
int n;
long long x[5005],d,ans,cnt,cnt2;
void dfs(int u,int v,int num){
	if(u==v){
		if(num<ans){
			ans=num;
			cnt=0;
		}
		if(num==ans){
			cnt++;
		}
		return;
	}
	if(num>ans)return;
	for(int i=v;i>u;i--){
		if(x[i]-x[u]<=d)dfs(i,v,num+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt2=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int u=1;u<=n;u++){
			for(int v=u+3;v<=n;v++){
				ans=1e9;
				cnt=0;
				dfs(u,v,0);
				if(cnt==2)cnt2++;
			}
		}
		cout<<cnt2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
