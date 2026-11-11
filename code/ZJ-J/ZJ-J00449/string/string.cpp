#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2100000],l,r,S;
char c[2100000];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l!=r){
		if(a[l]<a[r]){
			a[r]-=a[l];
			S+=a[l]*(c[l]!=c[r]);
			l++;
		}
		else{
			a[l]-=a[r];
			S+=a[r]*(c[l]!=c[r]);
			r--;
		}
	}
	cout<<S;
	return 0;
}
