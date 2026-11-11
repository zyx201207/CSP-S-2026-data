#include<bits/stdc++.h>
#define AC signed
#define AK return 0
#define int long long
using namespace std;
const string fwbs="This cpp is written by @hjcz_huls.";
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M],len,q[N];
bool f,flagA=1;
AC main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]) flagA=0;
	}
	if(flagA){
		for(int i=2;i<=n+1;i++)
		  if(a[i]!=a[i-1]) ans[a[i-1]]=i-1;
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		AK;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len;j++) q[j]=0;
		len=0;
		for(int j=i;j<=n;j++){
			f=1;
			for(int k=1;k<=len;k++){
				if(q[k]==a[j]){
					for(int l=k+1;l<=len;l++) q[l]=0;
					len=k,f=0;
					break;
				}
			}
			if(f) q[++len]=a[j];
		}
		for(int j=1;j<=len;j++) ans[q[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	AK;
}