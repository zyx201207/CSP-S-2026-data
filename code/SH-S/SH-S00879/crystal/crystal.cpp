#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
LL n,m,a[N],d[N],s[N],ans,cnt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(cnt+1,cnt+1+n);
	sort(a+1,a+1+n);//nlogn
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		s[i]=s[i-1]+d[i];
	}
	ans=1;
	for(int i=1;i<n;i++){
		if(d[i+1]==0){
			ans++;
		}
		else if(m>=i*d[i+1]){
			m-=i*d[i+1];
			ans=i+1;
		}else break;
	}
	cout<<ans<<endl;
	return 0;
}
