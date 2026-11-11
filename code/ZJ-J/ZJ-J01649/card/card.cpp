#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500001];
int b[500001];
int c[500001];
int d[500001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	int k=1;
	for(int i=1;i<=n;i++){
		b[a[i]]--;
		if(b[a[i]]>=1){
			d[a[i]]+=k;
			k=0;
		}else if(b[a[i]]==0){
			k+=d[a[i]];
			d[a[i]]=0;
		}
		c[a[i]]+=max(0LL,k);
		k++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
