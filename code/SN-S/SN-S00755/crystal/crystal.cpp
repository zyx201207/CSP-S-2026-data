#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
bool check(int s)
{
	long long sum = m,dis = a[s];
	for(int i = 1;i<=s;i++){
		sum-=(dis-a[i]);
		if(sum<0)return false;
	}
	return true;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];

	}

	sort(a+1,a+n+1);
	int l = 1,r = n;
	int ans = 1;
	while(l<r){
		int mid = (l+r)/2;
		if(check(mid)){
			l = mid+1;
			ans = mid;

		}
		else{
			r= mid-1;
		}
	}
	cout<<ans;
	return 0;
}
