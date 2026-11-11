#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,t[300005],b[300005],v[300005];
int main(){
	freopen("card3.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) b[i]=1;
	for(int i=1;i<=n;i++){
		if(v[a[i]]){
			for(int j=b[a[i]]+1;j<i;j++){
				if(v[a[j]]){
					v[a[j]]=0;
					b[a[j]]=i;
				}
			}
		}
		else t[a[i]]+=i-b[a[i]];
		v[a[i]]=1;
		b[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(!v[i]) t[i]+=n+1-b[i];
		cout<<n-t[i]<<' ';
	}
	return 0;
}