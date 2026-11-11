#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int n;
ll m;
ll a[maxn];

ll sum;
int maxi,maxj;
int maxs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sum=0;
	maxi=1;
	maxj=1;
	maxs=1;
	for (int l=1,r=1;r<=n;){
		if (a[r]>a[maxi]){
			sum+=(a[r]-a[maxi])*(r-l+1);
			maxj=maxi;
			maxi=r;
		}
		if (sum>m){
			l++;
			sum-=(a[maxi]-a[l]);
			if (l==maxi){
				sum-=(a[maxi]-a[maxj])*(r-l+1);
				maxi=maxj;
			}
			continue;
		}else{
			r++;
			maxs=max(maxs,r-l+1);
			sum+=a[r]-a[maxi];
		}
	}
	cout<<maxs;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}