#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
vector<int>v[N];
bool check(int x){
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			break;
		}
		ans=ans+(x-a[i]);
		cnt++;
		if(ans>m)break; 
	}
	v[x].push_back(cnt);
	if(ans>m)return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=a[1],r=a[n];
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<v[r][0];
	return 0;
}
