#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,l,r;
	ll res=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l = 1;
	r = n;
	while(l<r){
		int k=min(a[l],a[r]);
		a[l]-=k;
		a[r]-=k;
		if(c[l]!=c[r]){
			res+=k;
		}
		if(!a[l]){
			l++;
		}
		if(!a[r]){
			r--;
		}
	}
	cout<<res;
	return 0;
}
