#include<bits/stdc++.h>
using namespace std;
int a[200005];
int bucket[200005];
int prev[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<n;++i){
		for(int j=n;j>i;--j){
			if(a[i]==a[j]){
				prev[i]=j;
				break;
			} 
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int	first=a[j];
			bucket[first]++;
			if(prev[j]!=0) j=prev[j];
		}
	}
	for(int i=1;i<=m;++i){
		cout<<bucket[i]<<' ';
	}
	return 0;
}
