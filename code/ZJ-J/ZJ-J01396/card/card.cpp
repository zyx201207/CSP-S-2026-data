#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],c[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(a[n]==1)cout<<n<<' ';
		int s=0;
		for(int i=1;i<=n;i++)if(a[i]!=a[n])s++;
		cout<<s<<' ';
		if(a[n]==2)cout<<n;
		return 0;
	}
	if(n>5000){
		for(int i=1;i<=n;i++)if(a[i]>a[i-1]&&i!=1)cout<<i<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;b[a[j]]=j++)if(b[a[j]])for(int k=b[a[j]];k<j;k++)b[a[k]]=0;
		for(int j=1;j<=m;j++)if(b[j])c[j]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
