#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define ne next
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<ll>a;
	for(int i=0;i<n;i++){
		ll c;
		cin>>c;
		a.push_back(c);
	}
	sort(a.begin(),a.end());
	int l=0,r=n-1;
	while(l<r){
		int mid=(l+r+1)/2;
		//cout<<"mid="<<mid<<endl;
		
		bool check=false;
		int l1=0,l2=mid-1;
		ll sum=0;
		for(int i=0;i<mid-1;i++)sum+=a[i];
		while (l2!=n){
			sum+=a[l2];
			long long mx=a[l2]*mid;
			//cout<<"mx="<<mx<<endl<<"sum="<<sum<<endl;
			if(mx-sum<=m){
				check=true;
				break;
			}
			sum-=a[l1];
			l1++;
			l2++;
		}
		if(check)l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
