#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[m+1]={},c[m+1]={};
	cout<<3<<" "<<1<<" "<<4;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]+=1;
			if(b[a[j]]==2)
				b[a[j]]=1;
			for(int l=j-1;l>=0;l--){
				b[a[l]]-=1;
			}
		}
		for(int p=0;p<=m;p++){
			if(b[p]==1)
				c[p]+=1;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i];
	return 0;
}
