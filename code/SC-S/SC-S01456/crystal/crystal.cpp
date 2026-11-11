#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,h,ans=0,cnt=0,a[500005],b[500005],c[500005],v[100005],f=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[0]=0;
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
		if(i!=2&&b[i-1]!=b[i-2])f=0;
	}
	for(int i=1;i<n;i++){
		b[i]=b[i-1]+b[i];
	}
	if(f){
		h=m/b[1];
		for(int i=1;i<=n;i++){
			h-=i;
			if(h>=0){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	int l=n,r=n;
	while(l>=0&&r>=1){
		if(cnt>m||l==0){
			if(cnt>m)l+=2;
			else if(l==0)l+=1;
			ans=max(ans,r-l+1);
			//cout<<l<<' '<<r<<' '<<cnt<<"\n";
			cnt=0;
			r--;
			if(l==1){
				break;
			}
			l=r;
		}
		cnt+=(b[r-1]-b[l-1]);
		l--;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/