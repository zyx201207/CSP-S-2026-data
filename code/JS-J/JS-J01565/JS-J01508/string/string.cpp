#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,char> >a;
	for(int i=0;i<n;i++){
		int c;
		char t;
		cin>>c>>t;
		a.push_back({c,t});
	}
	int l=0,r=n-1;
	ll ls=a[0].first,rs=a[r].first;
	ll ans=0;
	while(l<r){
		if(a[l].second==a[r].second){
			if(ls>rs){
				ls-=rs;
				r--;
				rs=a[r].first;
			}
			else if(ls<rs){
				rs-=ls;
				l++;
				ls=a[l].first;
			}
			else{
				r--;
				rs=a[r].first;
				l++;
				ls=a[l].first;
			}
		}
		else{
			if(ls>rs){
				ls-=rs;
				ans+=rs;
				r--;
				rs=a[r].first;
			}
			else if(ls<rs){
				rs-=ls;
				ans+=ls;
				l++;
				ls=a[l].first;
			}
			else{
				ans+=rs;
				r--;
				rs=a[r].first;
				l++;
				ls=a[l].first;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
