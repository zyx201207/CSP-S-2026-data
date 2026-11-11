#include<bits/stdc++.h>
using namespace std;
int a[200013],b[200013],c[200013],isc=0,l,n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		l=0;memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			isc=0;
			for(int k=1;k<=l;k++){
				if(b[k]==a[j])isc=1;
				if(isc)b[l--]=0;
			}
			l++;
			b[l]=a[j];
		}
		for(int i=1;i<=m;i++){
			for(int j=i;j<=l;j++){
				if(b[j]==i)c[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}

