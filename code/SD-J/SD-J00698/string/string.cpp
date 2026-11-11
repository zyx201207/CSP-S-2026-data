#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
struct node{
	ll a;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll l=1,r,n,ans=0;cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	while(l<r){
		if(a[l].a>a[r].a){
			if(a[l].c!=a[r].c)ans+=a[r].a;
			a[l].a-=a[r].a;
			r--;
		}else{
			if(a[l].c!=a[r].c) ans+=a[l].a;
			a[r].a-=a[l].a;	
			l++;
		}
		if(a[l].a==0)l++;
		if(a[r].a==0) r--;
	} 
	cout<<ans;
	return 0;
}

