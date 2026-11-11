#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10;
int n,m,t,a[N],b[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,sizeof(b),0);
		t=0;
		for(int j=i;j<=n;j++){
			b[t++]=a[j];
		}
		for(int j=1;j<=t;j++){
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
