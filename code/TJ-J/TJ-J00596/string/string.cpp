#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,char>
const int N=2e5+5;
int n;
pii a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		ll num=0;		
		if(a[l].second==a[r].second){
			num=min(a[l].first,a[r].first);
			a[l].first-=num,a[r].first-=num;
			if(a[l].first==0) l+=1;
			else if(a[r].first==0) r-=1;
		}else{
			num=min(a[l].first,a[r].first);
			ans+=num;
			a[l].first-=num,a[r].first-=num;
			if(a[l].first==0) l+=1;
			else if(a[r].first==0) r-=1;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
