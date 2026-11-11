#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct st{
	int x,z;
};
st a[500005];
int b[500005];
int f[500005];
bool cmp(st w,st r){
	return w.z<r.z;
}
int ans,ans2;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		f[a[i].x]++;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[a[i].x]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i].z+=abs(a[i].x-a[j].x);
		}
	}
	sort(a+1,a+n+1,cmp);
	int t=a[1].x;
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=abs(a[i].x-t);
	}
	sort(b+1,b+n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=b[i];
		ans2++;
		if(sum>m){
			ans2--;
			break;
		}
	}
	cout<<max(ans,ans2);
	return 0;
}
