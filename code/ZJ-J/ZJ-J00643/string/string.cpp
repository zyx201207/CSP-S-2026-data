#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,l,r,ans,a[N];
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	l=1;r=n;
	while(l<r){
		if(a[l]<a[r]){
			a[r]-=a[l];
			if(ch[l]!=ch[r]) ans+=a[l];
			a[l]=0;l++;
		}
		else{
			a[l]-=a[r];
			if(ch[l]!=ch[r]) ans+=a[r];
			a[r]=0;r--;
		}
	}
	cout<<ans;
	return 0;
}
