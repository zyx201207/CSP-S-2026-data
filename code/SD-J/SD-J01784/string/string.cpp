#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,a[N],ans,l,r,sum,sum2;
bool f;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		if(c[l]!=c[r])f=1;
		else f=0;
		if(sum==0)sum=a[l];
		if(sum2==0)sum2=a[r];
		if(sum>sum2){
			if(f)ans+=sum2;
			r--;
			sum-=sum2;
			sum2=0;
			if(sum==0)l++;
		}
		else{
			if(f)ans+=sum;
			l++;
			sum2-=sum;
			sum=0;
			if(sum2==0)r--;
		}
	}
	cout<<ans;
	return 0;
}
