#include<bits/stdc++.h>
using namespace std;
int n,l,r;
char c[200001];
long long a[200001],q,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<=r){
		q=min(a[l],a[r]);
		if(c[l]!=c[r]){
			x+=q;
		}
		a[l]-=q;
		if(a[l]==0){
			l++;
		}
		a[r]-=q;
		if(a[r]==0){
			r--;
		}
	}
	cout<<x;
	return 0;
}
