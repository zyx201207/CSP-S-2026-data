#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
pair<int,char>a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].first,&a[i].second);
	}int l=1,r=n,sum=0;
	while(l<r){
		int minc=min(a[l].first,a[r].first);
		if(a[l].second!=a[r].second){
			sum+=minc;
		}a[l].first-=minc;
		a[r].first-=minc;
		if(a[l].first==0)l++;
		if(a[r].first==0)r--;
	}cout<<sum;
	return 0;
}
