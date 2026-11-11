#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[200010],b[200010],ma,j,mi,x,s;
void sc(int t,int p){
	int i,s;
	if(p==m+1){
		s=b[1];
		for (i=2;i<=m;i++) s&=b[i];
		ma=max(ma,s);return ;
	}
	if(t==n+1) return ;
	sc(t+1,p);
	b[p]=a[t];
	sc(t+1,p+1);
	b[p]=0;
}
int pd(int x){
	int s=0;
	while(x) s=s+x%2,x>>=1;
	return s;
}
int maxx(){
	int ma=0,i;
	for (i=1;i<=n;i++) ma=max(ma,a[i]);
	return ma;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	if(n<=20){sc(1,1),cout<<ma;return 0;}
	if(m==1){cout<<maxx();return 0;}
	if(m==n){
		ma=a[1];
		for (i=2;i<=n;i++) ma=(ma&a[i]);
		cout<<ma;return 0;
	}
	if(m==2){
		for (i=1;i<n;i++)
			for (j=i+1;j<=n;j++)
				ma=max(ma,a[i]&a[j]);
		cout<<ma;return 0;
	}
	for (i=1;i<=n;i++)
		if(pow(2,(int)log2(a[i]+1))==a[i]+1) s++;
	if(s==n){cout<<maxx();return 0;}
	for (i=1;i<=n;i++) ma=max(ma,a[i]);
	if(ma<4){
		for (i=1;i<=n;i++)
			b[a[i]]++;
		if(!b[3]){
			if(b[2]) cout<<0;
			else cout<<1;
			return 0;
		}
		if(b[3]>=m) cout<<3;
		else 
			if(b[3]+b[2]>=m) cout<<2;
			else 
			if(b[3]+b[1]>=m) cout<<1;
			else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
