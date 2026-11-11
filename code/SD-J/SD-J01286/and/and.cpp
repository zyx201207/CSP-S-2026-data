#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,c[200001],b[200001],a[200001];
void f(int k,int l){
	for(int i=l;i<=n;i++){
		if(b[i])continue;
		c[k]=i;
		b[i]=1;
		if(k==m){
			int sn=0x7ffffff;
			for(int i=1;i<=n;i++)if(!b[i])sn&=a[i];
			s=max(s,sn);
		}
		else f(k+1,i);
		b[i]=0;
	}
}
void f1(int k,int l){
	for(int i=l;i<=n;i++){
		if(b[i])continue;
		c[k]=i;
		b[i]=1;
		if(k==m){
			int sn=a[c[1]];
			for(int q=1;q<=m;q++)sn&=a[c[q]];
			s=max(s,sn);
		}
		else f1(k+1,i);
		b[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m>n/2){
		m=n-m;
		f(1,1);
		cout<<s;
	}
	else{
		f1(1,1);
		cout<<s;
	}
	return 0;
}
