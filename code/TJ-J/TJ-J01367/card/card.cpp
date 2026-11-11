#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long c[n],p[n],k[m],sum=0; 
	for(long long i=0;i<n;i++){
		cin>>c[i];
	}
	for(long long i=0;i<=m;i++){
		k[i]=0;
	}
	for(long long r=0;r<n;r++){
		sum=0;
		for(long long i=0;i<n;i++){
			p[i]=0;
		}
		for(int i=r;i<n;i++){
			for(long long j=0;j<sum;j++){
				if(p[j]==c[i]){
					long long x=0;
					for(long long v=j;v<sum;v++){
						p[v]=0;
						x++;
					}
					sum=sum-x;
					break;
				}
			}
			p[sum]=c[i];
			sum++;
		}
		for(long long i=0;i<sum;i++){
			long long e=p[i];
			k[e]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<k[i]<<' ';
	}
	return 0;
}
