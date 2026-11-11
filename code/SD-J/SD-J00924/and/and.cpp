#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int a[N],ans,n,m,b[N],c[N],tot,tott;
bool cmp(int a,int b){
	return a>b;
}signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)    cin>>a[i];
	for(int i=1;i<=n;i++)    b[i]=a[i];
	tot=n;
	for(int i=30;i>=0;i--){
		for(int j=1;j<=tot;j++)    c[j]=b[j];
		tott=tot,tot=0;
		for(int j=1;j<=tott;j++)	if((c[j]|(1<<i))==c[j])    b[++tot]=c[j];
		if(tot<m){
			tot=tott;
			for(int j=1;j<=tot;j++)    b[j]=c[j];
		}
	}sort(b+1,b+tot+1,cmp);
	ans=b[1];
	for(int i=2;i<=m;i++)    ans&=b[i];
	cout<<ans;
	return 0;
}//100
