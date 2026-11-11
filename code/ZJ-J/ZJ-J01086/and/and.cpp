#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int vis[200005];
int shuwei[200005][32];
int pw[30];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=30;i++) pw[i]=pw[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],f=0;
		while(x!=0){
			shuwei[i][f]=x%2;
			x/=2;
			f++;
		} 
	}
	for(int i=30;i>=0;i--){
		int s=0;
		for(int j=1;j<=n;j++){
			if(shuwei[j][i]==1) s++;
		}
		if(s>=m){
			for(int j=1;j<=n;j++){
				if(shuwei[j][i]==1) vis[j]+=pw[i];
			}
		}
	}
	sort(vis+1,vis+1+n,cmp);
	int ans=vis[1];
	for(int i=2;i<=m;i++) ans=ans&vis[i];
	cout<<ans;
	return 0;
}