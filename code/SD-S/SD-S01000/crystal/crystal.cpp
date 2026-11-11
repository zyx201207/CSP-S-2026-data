#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,l;
	cin>>n>>m;
	long long a[n+1],k,b[n+1];
	for(long long i=0;i<=n-1;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		l=0;
		k=m;
		for(long long j=0;j<n;j++) {
			b[j]=abs(a[j]-a[i]);
		}
		for(long long j=0;j<=k;j++){     
			for(long long p=0;p<n;p++){      
				if(b[p]==j && k>=b[p]){      
					l++;
					k-=b[p];
				}
			}
		}
		sum=max(sum,l);
	}
	cout<<sum;
	return 0;
}
