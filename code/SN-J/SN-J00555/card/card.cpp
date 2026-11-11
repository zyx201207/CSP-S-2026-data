#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5,M=3e5+5;
long long n,m,a[N],xb[M],cnt,k[M];
bool qf=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])qf=0;
	}
	if(qf){
		long long s=0;
		for(long long i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				s++;
			}else{
				s++;
				k[a[i]]+=s;
				s=i;
			}
		}
		for(long long i=1;i<=m;i++){
			cout<<k[i]<<' ';
		}
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n])k[a[n]]++;
			k[a[i]]++;
		}
		cout<<k[1]<<' '<<k[2];
	}
	if(n*n*m<=300000000){
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				if(!xb[a[j]]){
					xb[a[j]]=++cnt;
				}else{
					for(long long ii=1;ii<=m;ii++){
						if(xb[ii]>xb[a[j]]){
							xb[ii]=0;
							cnt--;
						}
					}
					xb[a[j]]=++cnt;
				}
			}
			for(long long j=1;j<=m;j++){
				if(xb[j]){
					xb[j]=0;
					k[j]++;
				}
			}
			cnt=0;
		}
		for(long long i=1;i<=m;i++){
			cout<<k[i]<<' ';
		}
		return 0;
	}
	for(long long i=n;i>=1;i--){
		if(!xb[a[i]]){
			xb[a[i]]=++cnt;
		}else{
			for(long long j=i+1;j<=xb[a[i]];j++){
				if(!xb[a[j]])continue;
				xb[a[j]]=0;
				cnt--;
			}
			xb[a[i]]=++cnt;
		}
		for(long long j=1;j<=m;j++){
			if(xb[j]){
				k[j]++;
			}
		}
	}
	for(long long i=1;i<m;i++){
		cout<<k[i]<<' ';
	}
	cout<<n;
	return 0;
}
