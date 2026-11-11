#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,m,ma=LLONG_MIN;
int ad[N+10],p[N+10],t[N+10];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>t[i];
	sort(t+1,t+n+1,cmp);
	for(long long i=2;i<=n;i++){
		ad[i-1]=t[i-1]-t[i];
		p[i-1]+=ad[i-1]+p[i-2];
	}
	for(long long i=1;i<n;i++){
		if(i!=1) for(int j=i;j<n;j++){
			p[j]-=ad[i-1];			
		}
		long long z=m;
		long long c=0;
		int pzt=i;
		for(;pzt<=n;){
			z=z-p[pzt++];
			c++;
			if(z<0){				
				break;
			}
		}
		ma=max(ma,c);
	}
	cout<<ma;
	return 0;
}
