#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxn1=3e5+10;
int n,m,a[maxn],b[maxn],v[maxn1];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=1;
		for(int j=i;j<=n;j++){
			memset(b,0,sizeof(0));
			for(int k=1;k<=sum;k++){
				if(b[k]==a[j]){
					sum=k;
					break;
				}
			}
			b[sum++]=a[j];
		}
		for(int j=1;j<=sum;j++)v[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<v[i]<<' ';
	return 0;
}
