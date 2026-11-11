#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
struct point{
	ll l,r;
	char id;
};
int n;
ll pos;
ll tot;
point a[N],b[N];
pair<ll,char> s[N];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	pos=1;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
		a[i].l=pos;
		a[i].r=pos+s[i].first-1;
		a[i].id=s[i].second;
		pos+=s[i].first;
	}
	tot=pos-1;
	pos=1;
	for(int i=1;i<=n;i++){
		int j=n-i+1;
		b[i].l=pos;
		b[i].r=pos+s[j].first-1;
		b[i].id=s[j].second;
		pos+=s[j].first;
	}
	int i=1,j=1;
	while(i<=n&&j<=n){
		if(a[i].id==b[j].id){
			if(a[i].r==b[j].r) i++,j++;
			else if(a[i].r<b[j].r) i++;
			else j++;
		}
		else{
			
			ll L=max(a[i].l,b[j].l);
			ll R=min(a[i].r,b[j].r);
			ans+=R-L+1;
			if(a[i].r==b[j].r) i++,j++;
			else if(a[i].r<b[j].r) i++;
			else j++;
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}

