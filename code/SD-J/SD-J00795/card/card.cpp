#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],c[N],d,p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					p=k-1;
					break;
				}
			}
			b[++l]=a[j];
		}
		for(int j=1;j<=c;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
