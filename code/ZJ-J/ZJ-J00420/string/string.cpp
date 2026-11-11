#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum,ans;
struct S{
	ll x;
	char c;
}a[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].x>a[r].x){
			a[l].x-=a[r].x;
			ans+=a[r].x*(a[l].c!=a[r].c);
			r--;
		}
		else{
			a[r].x-=a[l].x;
			ans+=a[l].x*(a[l].c!=a[r].c);
			l++;
		}
	}
	cout<<ans;
	return 0;
}