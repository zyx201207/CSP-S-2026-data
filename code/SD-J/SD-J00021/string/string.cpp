#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200010;
struct node{
	ll k;
	char b;
}a[N];
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].b;
	}
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[l].k<a[r].k){
			if(a[l].b!=a[r].b){
				ans+=a[l].k;
				//cout<<a[l].k<<" "<<a[l].b<<" "<<a[r].k<<" "<<a[r].b<<endl;
			}
			a[r].k-=a[l].k;
			l++;
		}else if(a[l].k==a[r].k){
			if(a[l].b!=a[r].b){
				ans+=a[l].k;
				//cout<<a[l].k<<" "<<a[l].b<<" "<<a[r].k<<" "<<a[r].b<<endl;
			}
			l++,r--;
		}else{
			if(a[l].b!=a[r].b){
				ans+=a[r].k;
				//cout<<a[l].k<<" "<<a[l].b<<" "<<a[r].k<<" "<<a[r].b<<endl;
			}
			a[l].k-=a[r].k;
			r--;
		}
	}
	cout<<ans;
}
