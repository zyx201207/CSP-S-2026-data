#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[500005],num=0x3f,ans,b,c,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			continue;
		}
		f=i;
		break;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			cnt[i]=abs(a[i]+a[f]);
		}
	}
	sort(cnt+1,cnt+n);
	for(int i=1;i<=n-1;i++){
		cnt[i]=abs(a[1]-a[i]);
	}
	for(int i=1;i<=n-1;i++){
		ans+=cnt[i]*c;
		b++;
		if(ans>m){
			break;
		}
	}
	cout<<b+1;
	return 0;
}