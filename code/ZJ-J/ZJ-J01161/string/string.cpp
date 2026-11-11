#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],ss,ls,rs,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ss+=a[i];
	}
	char cc;
	while(l<=r){
		if(ls<=rs){
			if(c[l]!=cc){
				if(ls+a[l]>rs) ans+=rs-ls;
				else ans+=a[l];
			}
			ls+=a[l];
			if(ls>rs){
				cc=c[l];
			}
			l++;
		}
		else if(ls>rs){
			if(c[r]!=cc){
				if(rs+a[r]>ls) ans+=ls-rs;
				else ans+=a[r];
			}
			rs+=a[r];
			if(ls<rs){
				cc=c[r];
			}
			r--;
		}
	}
	cout<<ans;
}
