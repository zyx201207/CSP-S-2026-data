#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n;
ll sum[N]={},a[N],cnt[N],ans=0;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum[i]=sum[i-1]+a[i];
		cnt[i]=a[i];
	}
	int l=1,r=n;
	while(l<r){
		int ed=r;
		while(cnt[l]!=0){
			if(s[l]!=s[ed]){
				ans+=min(cnt[l],cnt[ed]);
			}
			
			int x=min(cnt[l],cnt[ed]);
			cnt[l]-=x;
			cnt[r]-=x;
			
			if(cnt[ed]==0) ed--;
		}
		l++;
		if(cnt[ed]==0) r=ed-1;
		else r=ed;
	}
	cout<<ans;
	return 0;
}
