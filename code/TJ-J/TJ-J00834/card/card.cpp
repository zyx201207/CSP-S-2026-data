#include<bits/stdc++.h>
using namespace std;
const int CNT=300009;
int a[CNT];
int b[CNT];
int bz[500009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,ct=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>bz[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1+ct;j<=n;j++){
			a[bz[j]]++;
			for(int k=1;k<=m;k++){
				if(a[k]==2){
					memset(a,0,sizeof(a));
					a[bz[j]]++;
					break;
				}
			}
		}
		
		
		for(int j=1;j<=m;j++){
			b[j]+=a[j];
		}
		ct++;
		memset(a,0,sizeof(a));
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
