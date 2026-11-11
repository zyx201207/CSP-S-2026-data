#include<bits/stdc++.h>
using namespace std;
#define C ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
struct node{
	int b;
	string rs;
}a[200005];
int main(){
	C
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		cin>>a[i].rs;
		len+=a[i].b;
	}
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[l].b>a[r].b){
			if(a[l].rs!=a[r].rs){
				ans+=a[r].b;
			}
			a[l].b-=a[r].b;
			r--;
		}else if(a[r].b>a[l].b){
			if(a[l].rs!=a[r].rs){
				ans+=(a[l].b);
			}
			a[r].b-=a[l].b;
			l++;
		}else{
			if(a[l].rs!=a[r].rs){
				ans+=(a[l].b);
			}
			a[l].b=0;
			a[r].b=0; 
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
