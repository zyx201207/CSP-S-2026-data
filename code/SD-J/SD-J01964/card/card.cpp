#include<bits/stdc++.h>
using namespace std;
long long a[100000],b[100000],btop=0,ans[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++){
		btop=0;
		for(long long j=0;j<=n;j++)b[j]=0;
		for(long long j=i;j<=n;j++){
			bool pd=0;
			long long bjk=0;
			for(long long k=1;k<btop;k++)
				if(b[k]==a[j]){
					pd=1,bjk=k;
					break;
				}
			if(pd==1)btop=bjk;
			else{
				btop++;
				b[btop]=a[j];
			}
		}
		for(long long j=1;j<=btop;j++)
			ans[b[j]]++;
	}
	for(long long i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
} 
