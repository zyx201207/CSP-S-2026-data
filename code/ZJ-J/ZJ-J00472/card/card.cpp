#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,a[N],b[N],s[N],e[N],i=1,j;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(;i<=n;i++) cin>>a[i];
	for(i=n;i>=1;i--){
		b[a[i]]++;
		if(b[a[i]]==1) s[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		j=s[a[i]];
		while(j<=n){
			if(j!=s[a[j]]) j=s[a[j]];
			e[a[j]]++;
			j++;
		}
	}
	for(i=1;i<=m;i++) cout<<e[i]<<" ";
	return 0;
}
