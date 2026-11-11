#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN],b[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[0]=a[0];
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=n;i>=1;i--){
		int j=1;
		int mi=1,ma=i;
		while(mi!=ma){
			int cmp;
			cmp=(mi+ma)/2;
			if(a[i]*(i-cmp+1)-(b[i]-b[cmp-1])>m){
				mi=cmp+1;
			}
			else{
				ma=cmp;
			}
		}
		if(i-ma+1>ans)ans=i-ma+1;
	}
	cout<<ans;
	return 0;
}
