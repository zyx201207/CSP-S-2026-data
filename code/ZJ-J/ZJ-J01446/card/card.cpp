#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],x[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			x[a[i]]++;
			if(a[i]!=a[n]) x[a[n]]++;
		}
		cout<<x[1]<<" "<<x[2];
		return 0;
	}
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++){
			int l=0;
			for(int j=i;j<=n;j++){
				for(int k=l;k>0;k--){
					if(d[k]==a[j]){
						l=k-1;
						break;
					}
				}
				d[++l]=a[j];
			}
			for(int i=1;i<=l;i++){
				x[d[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<x[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) x[a[i]]+=i;
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
	return 0;
}
