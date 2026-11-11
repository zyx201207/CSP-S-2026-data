#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct nd{
	ll lst;
	char c;
}a[200005];

int n;
ll ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].lst >> a[i].c;
	}
	for(int l=1,r=n;l<r;){
		if(a[l].c!=a[r].c){
			ans+=min(a[l].lst , a[r].lst);
		}
		if(a[l].lst < a[r].lst){
			a[r].lst-=a[l].lst;
			l++;
		}else if(a[l].lst > a[r].lst){
			a[l].lst-=a[r].lst;
			r--;
		}else{
			l++,r--;
		}
	}
	cout << ans;
	return 0;
}
