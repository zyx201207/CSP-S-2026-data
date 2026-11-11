#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],x,ii;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++){
			c[i]=a[i];
			for(int k=1;k<i;k++){
				if(c[k]==a[i])
					x=0;
				if(x==0){
					c[k]=x;
				}
			}
			x=1;
		}
		for(int i=p;i<=n;i++){
			if(c[i]==0)
				continue;
			b[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
