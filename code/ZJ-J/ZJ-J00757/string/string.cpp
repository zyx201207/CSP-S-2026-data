#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,i,x,y,l,r,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	l=1;r=n;x=a[1];y=a[n];
	while(l<=n&&r>=1){
		if(x<=y){
			if(c[l]!=c[r])
				ans+=x;
			y=y-x;x=a[++l];
		}
		else{
			if(c[l]!=c[r])
				ans+=y;
			x=x-y;y=a[--r];
		}
	}
	cout<<ans/2;
}