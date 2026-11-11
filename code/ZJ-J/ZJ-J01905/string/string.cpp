#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
pair<int,char> a[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	int l=1,r=n;
	while(l<=r){
		if(a[l].first!=a[r].first){
			if(a[l].first>a[r].first){
				a[l].first-=a[r].first;
				if(a[l].second!=a[r].second)ans+=a[r].first;
				r--;
			}
			else {
				a[r].first-=a[l].first;
				if(a[l].second!=a[r].second)ans+=a[l].first;
				l++;
			}
		}
		else if(a[l].second!=a[r].second){
			ans+=a[l].first;
			l++,r--;
		}
		else l++,r--;
	}
	cout<<ans;
	return 0;
}