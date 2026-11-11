#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+100;
long long n,m,sumn=1;
long long a[N],b[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	b[n]=0;
	for(long long i=n-1;i>=1;i--)	b[i]=b[i+1]+a[i+1]-a[i];
	for(long long i=1;i<=n;i++){
		long long c=0,sum=0;
		bool sf=true;
		for(long long j=i;j>=1&&sf;j--){
			if(m-c>=b[j]-b[i]){
				sum++;
				c=c-b[i]+b[j];
			}
			else sf=false;
		}
		sumn=max(sumn,sum);
	}
	cout<<sumn;
	return 0;
}