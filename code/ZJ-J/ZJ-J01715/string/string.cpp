#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
pair<int,char> a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		if(a[l].first>a[r].first){
			if(a[l].second!=a[r].second){
				ans+=a[r].first;
			}
			a[l].first-=a[r].first;
			r--;
		}else if(a[l].first<a[r].first){
			if(a[l].second!=a[r].second){
				ans+=a[l].first;
			}
			a[r].first-=a[l].first;
			l++;
		}else{
			if(a[l].second!=a[r].second){
				ans+=a[l].first;
			}
			l++;
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
