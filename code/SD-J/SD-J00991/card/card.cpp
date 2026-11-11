#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],n,m,c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[a[i]]+=i;
	}
	for(int i=n;i>=1;i--){
		if(c[a[i]]!=0){
			for(int j=i;j<c[a[i]];j++){
				b[a[j]]-=1;
			}
		}
		else{
			c[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
