#include <bits/stdc++.h>
using namespace std;
int const N=5e5+10;
int n,m;
int a[N],b[N],sum[N],w[N],w_w[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		w[i]=a[i];
	}
	for(int c=1;c<=n;c++){
		for(int x=1;x<=n;x++){
			b[x]=0;
			a[x]=w[x];
		}
		for(int i=c;i<=n;i++){
		if(b[a[i]]!=0){
			for(int j=b[a[i]];j<i;j++){
				a[j]=0;
				b[a[j]]=0;
			}
		}
		b[a[i]]=i;
		}
		for(int j=c;j<=n;j++){
			sum[a[j]]++;
		}	
}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
