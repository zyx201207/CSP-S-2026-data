#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],t[300005],l,r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],t[a[i]]++;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=m;i++) t[a[i]]+=t[a[i]-1];
	for(int i=1;i<=m;i++){
		cout<<t[a[i]]<<" ";
	}
	return 0;
} 
