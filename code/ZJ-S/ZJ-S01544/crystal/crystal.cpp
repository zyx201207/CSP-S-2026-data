#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 514514
LL n,m,a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	LL ans=0;
	LL cur=0;
	LL cnt=1;
	for(LL i=1,j=1;i<=n;){
		while(cur>m&&j<=i){
			cur-=a[i]-a[j++];
			cnt--;
		}
//		cout<<"test: "<<j<<" "<<i<<" "<<cur<<endl;
		ans=max(ans,cnt);
		cur+=cnt*(a[i+1]-a[i]);
		cnt++,i++;
	}
	cout<<ans<<endl;
	return 0;
}
