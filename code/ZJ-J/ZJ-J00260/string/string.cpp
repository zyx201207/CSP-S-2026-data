#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n;
struct node{
	char c;
	ll num;
}a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	ll l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].num==a[r].num){
				a[l].num=0;
				a[r].num=0;
				l++;r--;
			}else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}else if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}
		}else{
			if(a[l].num==a[r].num){
				ans+=a[l].num;
				a[l].num=0;
				a[r].num=0;
				l++;r--;
			}else if(a[l].num<a[r].num){
				ans+=a[l].num;
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}else if(a[l].num>a[r].num){
				ans+=a[r].num;
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
