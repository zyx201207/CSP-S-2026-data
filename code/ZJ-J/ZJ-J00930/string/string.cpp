#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,char> a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		sum+=a[i].first;
	}
	int k=sum/2;
	int ans=0;
	int l=1,r=n;
	while(r>=l){
		//左装下右 
		if(a[l].first>=a[r].first){
			if(a[l].second!=a[r].second) ans+=a[r].first;
			a[l].first-=a[r].first;
			if(a[l].first==0) l++;
			r--;
		} 
		//装不下 
		else{
			if(a[l].second!=a[r].second) ans+=a[l].first;
			a[r].first-=a[l].first;
			if(a[r].first==0) r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
