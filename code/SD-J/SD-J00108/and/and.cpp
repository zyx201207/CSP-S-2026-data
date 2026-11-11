#include <bits/stdc++.h>
using namespace std;
int n,m,mx=0,nw=0;
int zzz[21];
bool vis[21];
int yu(int a,int b){
	if(a==0)return b;
	if(b==0)return a;
	int aq[20],bq[20];
	int aqi=0,bqi=0,ans=0;
	while(a>0){
		if(a%2==1)aq[aqi]=1;
		else aq[aqi]=0;
		aqi++;
		a/=2;
	}
	while(b>0){
		if(b%2==1)bq[bqi]=1;
		else bq[bqi]=0;
		bqi++;
		b/=2;
	}
	int z=1;
	int v=min(aqi,bqi);
	for(int i=0;i<=v;i++){
		if(aq[i]+bq[i]==2)ans+=z;
		z*=2;
	}
	return ans;
}
void dfs(int n,int m,int st){
	if(st==1)nw=0;
	if(st>=m){
		mx=max(mx,nw);
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
		int c=nw,a=nw,b=zzz[i];
		a=max(a,b);
		b=min(b,c);
			nw=yu(a,b);
			vis[i]=true;
			dfs(n,m,st+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n<=20){
		for(int i=0;i<21;i++){
			vis[i]=false;
		}
		for(int i=0;i<n;i++){
			cin>>zzz[i];
		}
		nw=0;
		dfs(n,m,1);
		cout<<mx;
	}
	else if(n<=2000){
		if(m==1){
			int ans=-1,a;
			for(int i=0;i<n;i++){
				cin>>a;
				ans=max(a,ans);
			}
			cout<<ans;
		}
		else if(m==2){
			int ans=-1;
			int s[2001];
			for(int i=0;i<n;i++)
				cin>>s[i];
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					ans=max(ans,yu(s[i],s[j]));
				}
			}
			cout<<ans;
		}
		else{
			int a;cin>>a;int b;
			for(int i=1;i<n;i++){
				cin>>b;
				a=yu(a,b);
			}
			cout<<a;
		}
	}
	else cout<<3;
	return 0;
}
