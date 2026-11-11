#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005]; 
int maxx=-1;
void dfs(int x,int i,int ans){
	if(x==m){
		maxx=max(maxx,ans);
		return;
	}
	if(i==n+1){
		return;
	}
	int an=ans;
	if(ans==-1) ans=a[i];
	else ans&=a[i];
	dfs(x+1,i+1,ans);
	ans=an;
	dfs(x,i+1,ans);
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
  	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=-1;
	int am=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) am=a[i];
		else am&=a[i];
		ma=max(ma,a[i]);
	}
	if(n<=20){
		dfs(0,1,-1);
		cout<<maxx;
		return 0;
	}
	if(m==1){
		cout<<ma;
		return 0; 
	}
	if(m==n){
		cout<<am;
		return 0;
	}
	if(m==2){
		int maa=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maa=max(maa,a[i]&a[j]);
			}
		}
		cout<<maa;
		return 0;
	}
	if(ma<4){
		int c1=0,c2=0,c3=0,c0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) c1++;
			if(a[i]==2) c2++;
			if(a[i]==3) c3++;
			if(a[i]==0) c0++; 
		}
		if(c3>m) cout<<3;
		else if(c3+c2>m) cout<<2;
		else if(c3+c1>m) cout<<1;
		else cout<<0;
		return 0; 
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
//yang guan zi wei zhi xing ti,fu cha jiang xing zhao tie yi
//Ñö¹Û×ÏÞ±ÖªÐËÌæ£¬¸©²ì½«ÐÇÕÕÌúÒÂ 
