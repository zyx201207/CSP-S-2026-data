#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,char> >a;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int last=0;
	a.push_back({0,'a'});
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		last+=x;
		a.push_back({last,y});
		
	}
	int ans=0,l=1,r=a.size()-1;
	while(l<=r){
		if(a[l].first>last/2){
			break;
		}
		if(a[l].second!=a[r].second){
			int minn=min(a[l].first-a[l-1].first,last-a[r-1].first);
			ans+=minn;
			if(a[l].first-a[l-1].first<last-a[r-1].first){
				a[r-1].first-=minn;
				l++;
				
			}else if(a[l].first-a[l-1].first>last-a[r-1].first){
				a[l-1].first+=minn;
				r--;
			}else{
				l++;r--;
			}
		}else{
			int minn=min(a[l].first-a[l-1].first,last-a[r-1].first);
			if(a[l].first-a[l-1].first<last-a[r-1].first){
				a[r-1].first-=minn;
				l++;
				
			}else if(a[l].first-a[l-1].first>last-a[r-1].first){
				a[l-1].first+=minn;
				r--;
			}else{
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 





