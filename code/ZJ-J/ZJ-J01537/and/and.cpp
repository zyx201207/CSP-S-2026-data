#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const long long N=2e5+10,M=32;
long long n,m,x,cnt,ans,a[N][M],A[N],ANS[M];
bool IS[N];
vector<long long> v;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x;
		A[i]=x;
		long long t=0;
		while(x){
			t++;
			long long tmp=x%2;
			x/=2;
			a[i][t]=tmp;
		}
		v.pb(i);
	}
	for(long long i=31;i>=1;i--){
		cnt=0;
		for(long long j=0;j<v.size();j++){
			x=v[j];
			IS[x]=0;
			if(a[x][i]==1){
				cnt++;
				IS[x]=1;
			} 
		}
		if(cnt>=m){
			v.clear();
			for(long long j=1;j<=n;j++){
				if(IS[j]){
					v.pb(j);
				}
			}
			ANS[i]=1;
		}
	}
	long long t=1;
	for(long long i=1;i<=31;i++){
		ans+=ANS[i]*t;
		t*=2;
	}
	cout<<ans;
	return 0;
}
