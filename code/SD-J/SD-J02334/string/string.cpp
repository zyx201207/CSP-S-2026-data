//T2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
struct node{
	ll len;char da;
	node(){
		len=1;
	}
}a[N];
map<ll,int>_find;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].len>>a[i].da;
	}
	ll l=1,r=n,ans=0;
	while(l<r){
		if(a[l].da!=a[r].da){
			if(a[l].len==a[r].len){
				ans+=a[l].len;l++,r--;continue;
			}else if(a[l].len<a[r].len){
				ans+=a[l].len;a[r].len-=a[l].len;l++;continue;
			}else{
				ans+=a[r].len;a[l].len-=a[r].len;r--;continue;
			}
		}else{
			if(a[l].len==a[r].len){
				l++,r--;continue;
			}else if(a[l].len<a[r].len){
				a[r].len-=a[l].len;l++;continue;
			}else{
				a[l].len-=a[r].len;r--;continue;
			}
		}
	}
	cout<<ans;
	return 0;
}

