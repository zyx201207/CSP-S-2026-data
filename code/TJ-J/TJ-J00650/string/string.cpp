#include<bits/stdc++.h>
using namespace std;
#define N 200005
long long n,a[N],ans,cnt[N],minn;
char c[N];
string s;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt[i]=cnt[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<r){
		minn=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=minn;
		}
		a[l]-=minn,a[r]-=minn;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
    return 0;
}
