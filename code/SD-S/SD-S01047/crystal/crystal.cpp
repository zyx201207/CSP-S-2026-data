#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long a[maxn],m,sum;
int n,l,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	for(int r=1;r<=n;r++){
		sum+=a[r];
		while(l<r && (r-l+1)*a[r]-sum >m){
			l++;
			sum-=a[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}


