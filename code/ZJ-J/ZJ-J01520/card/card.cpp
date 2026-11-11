#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000],s[310000],tab[510000],p=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		p=1;
		for(long long j=i;j<=n;j++){
			long long t=p;
			for(long long k=1;k<=p;k++){
				if(tab[k]==a[j]){
					p=k;
					break;
				}
			}
			if(t==p) tab[++p]=a[j];
//			for(long long k=1;k<=p;k++) cout<<tab[k]<<' ';
//			cout<<endl;
		}
		for(long long j=1;j<=p;j++){
//			cout<<tab[j]<<' ';
			s[tab[j]]++;
		}
//		cout<<endl<<endl;
	}
	for(long long i=1;i<=m;i++) cout<<s[i]<<' ';
	return 0;
}
