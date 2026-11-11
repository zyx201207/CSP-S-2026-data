#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,i,j,a[200100],s=0;
char c[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			s+=min(a[l],a[r]);
		}
		if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
			    l++;
				r--;
			}
		}
	}
	cout<<s;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/