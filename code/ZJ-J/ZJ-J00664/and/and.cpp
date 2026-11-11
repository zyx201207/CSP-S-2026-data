#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,sum=0;
unsigned long long g[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(unsigned long long i=1;i<=n;i++){
		cin>>g[i];
	}
	for(unsigned long long i=1;i<=n;i++){
		for(unsigned long long j=i+1;j<=n;j++){
			unsigned long long tmpi=g[i],tmpj=g[j];
			unsigned long long tmpsum=0,x=0;
			while(tmpi||tmpj){
				unsigned long long ti=tmpi%2,tj=tmpj%2;
				if(ti&tj){
					tmpsum+=pow(2,x);
				}
				tmpi/=2,tmpj/=2;
				x++;
			}
			sum=max(sum,tmpsum);
		}
	}
	cout<<sum<<endl;
	return 0;
}
