#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,d[N],l,r,k;
char c[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>c[i];
	}
	l=1,r=n;
	while(l<=r){
		if(d[l]<d[r]){
			if(c[l]!=c[r]) k+=d[l];
			d[r]-=d[l];
			l++;
		}else if(d[l]>d[r]){
			if(c[l]!=c[r]) k+=d[r];
			d[l]-=d[r];
			r--;
		}else{
			if(c[l]!=c[r]) k+=d[r];
			r--;
			l++;
		}
	}
	cout<<k;
	return 0;
}
