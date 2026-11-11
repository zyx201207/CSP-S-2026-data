#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=5e5+10;
int n,m,an[N];
int bn[N];
int g=0;
map<int,int> mp;
int search(int x){
	int l=0,r=g+1;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(bn[mid]<=x){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	sort(an+1,an+n+1);
	for(int i=2;i<=n;i++){
		int j=i-1;
		if(an[i]>an[j]){
			sum+=(an[i]-an[j])*j;
			bn[++g]=sum;
			mp[g]=i;
		}
		if(an[i]==an[j]) mp[g]++;
	}
	cout<<mp[search(m)];
	return 0;
}
