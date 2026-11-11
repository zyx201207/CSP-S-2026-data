#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+24;
int n,ans;
int a[N];
char c[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
		
	for(int l=1,r=n;l<=r;){
		if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r])ans+=a[r];
			l++;r--;
		}
	}
	cout<<ans;
	return 0;
}
