#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,l,r;
ll a[N],ans,res;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		if(a[l]>=a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}else{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
