#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt=0;
struct Nod{
	ll id;
	char ch;
};
Nod a[234567];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(NULL);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].id>>a[i].ch;
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l].ch!=a[r].ch){
			cnt+=min(a[l].id,a[r].id);
		}
		if(a[l].id>a[r].id){
			a[l].id-=a[r].id;
			r--;
		}
		else if(a[l].id<a[r].id){
			a[r].id-=a[l].id;
			l++;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}


