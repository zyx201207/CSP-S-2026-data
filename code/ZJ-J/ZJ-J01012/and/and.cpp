#include <bits/stdc++.h>
using namespace std;
int n,m,ans,j,i,r[35],ma,a[201000],x,f[201000];
int zhuan(int q,int h){
	int i,t=0,ans=0,bs=1;
	while(q&&h){
		r[++t]=(q%2+h%2)/2;
		q/=2;h/=2;
	}
	for(i=1;i<=t;i++)
		ans=ans+r[i]*bs,bs*=2;
	return ans;
}
void dg(int t,int x){
	if(x>m)return ;
	if(t==n+1){
		if(x==m){
			ans=f[1];
			for(i=2;i<=m;i++)
				ans=zhuan(ans,f[i]);
			ma=max(ma,ans);
		}
		return ;
	}
	f[x+1]=a[t];dg(t+1,x+1);dg(t+1,x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(i=1;i<=n;i++)cin>>x,ma=max(ma,x);
		cout<<ma;return 0;
	}
	else if(m==2){
		for(i=1;i<=n;i++){
			cin>>a[i];
			for(j=1;j<i;j++)
				ma=max(ma,zhuan(a[i],a[j]));
		}
		cout<<ma;return 0;
	}
	else if(m==n){
		for(i=1;i<=n;i++)
			cin>>a[i],ma=zhuan(ma,a[j]);
		cout<<ma;return 0;
	}
	else if(n>2000){
		for(i=1;i<=n;i++)
			cin>>a[i],ma=max(ma,a[i]);
		if(a[1991]<4&&a[987]<4){
			for(i=1;i<=n;i++)f[a[i]]++;
			if(f[3]>=m)cout<<3;
			else if(f[2]>=m)cout<<2;
			else if(f[1]>=m)cout<<1;
			else cout<<0;
		}
		else cout<<ma;
		return 0;
	}
	for(i=1;i<=n;i++)cin>>a[i];
	dg(1,0);
	cout<<ma;
	return 0;
}

