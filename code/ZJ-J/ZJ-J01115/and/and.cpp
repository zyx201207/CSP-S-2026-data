#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200105],ans,pw[32],maxp;
bool b[200105][32],c[32];
void abc(long long x,long long p){
	for(long long j=31;j>=0;j--){
		if(x>=pw[j]){
			b[p][j]=true;
			x-=pw[j];
			maxp=max(maxp,j);
		}
		else b[p][j]=false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pw[0]=1;
	for(long long i=1;i<=31;i++)pw[i]=pw[i-1]*2;
	for(long long i=1;i<=n;i++)cin>>a[i],abc(a[i],i);
	for(long long i=maxp+1;i>=0;i--){
		long long t=0;
		for(long long j=1;j<=n;j++){
			bool abcd=true;
			for(long long k=maxp+1;k>i;k--){
				if(c[k]==true&&b[j][k]==false)abcd=false;
			}
			if(abcd&&b[j][i]==true)t++;
		}
		if(t>=m)c[i]=true;
	}
	for(long long i=31;i>=0;i--){
		if(c[i])ans+=pw[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

