#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll a[500009];
int f(){
	memset(a,0,sizeof(a));
	int n;
	ll am;
	cin>>n;
	cin>>am;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0,r=0,x=1;
	ll v=1;
	ll s=0;
	for(;l<n;l++){
		if(l>0){
			if(r<l){
				v=1;
				r=l;
				s=0;
			}else{
				v--;
				s-=a[r]-a[l];
			}
		}
		while(r<n-1&&s+(a[r+1]-a[r])*v<=am){
			s+=(a[r+1]-a[r])*v;
			r++;
			v++;
		}
		x=max(x,r-l+1);
	}
	return x;
}
int main(){
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cout<<f();
	return 0;
}
