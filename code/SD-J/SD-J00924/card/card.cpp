#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int a[N],ans,n,m,b[N],k[N],l=0;
map<int,int>ma;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m<=2){
		for(int i=1;i<=n;i++)    cin>>a[i];
		b[a[n]]+=n;
		if(a[n]!=a[n-1]){
			for(int i=n-1;i>=1;i--)
				if(a[i]==a[n-1])    b[a[n-1]]++;
				else    break;
		}for(int i=1;i<=m;i++)    cout<<b[i]<<' ';
		return 0;
	}for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]+=i;
		if(ma[a[i]]!=0)    for(int j=ma[a[i]];j<i;j++)    k[j]=max(ma[a[i]],k[j]);
		ma[a[i]]=i;
	}for(int i=1;i<=n;i++)    b[a[i]]-=k[i];
	for(int i=1;i<=m;i++)    cout<<b[i]<<' ';
	return 0;
}//36
