#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],sum,l=1,r,sl,sr,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sl=a[1],sr=a[n];
	while(l<r){
		if(sl==sr){
			if(c[l]!=c[r]){
				ans+=sl;
			}
			l++,r--;
			sl=a[l],sr=a[r];
		}
		else if(sl>sr){
			if(c[l]!=c[r]){
				ans+=sr;
			}
			sl-=sr;
			r--;
			sr=a[r];
		}
		else{
			if(c[l]!=c[r]){
				ans+=sl;
			}
			sr-=sl;
			l++;
			sl=a[l];
		}
	}
	cout<<ans;
	return 0;
}