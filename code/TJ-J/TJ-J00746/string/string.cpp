#include<bits/stdc++.h>
using namespace std;
long long n,L,cnt[200005],l,r,ans;char c[200005];
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>cnt[i]>>c[i],L+=cnt[i];
	l=1,r=n;
	while(l<r){
		if(cnt[l]<cnt[r])
			ans+=(c[l]!=c[r])*cnt[l],cnt[r]-=cnt[l],l++;
		else if(cnt[l]>cnt[r])
			ans+=(c[l]!=c[r])*cnt[r],cnt[l]-=cnt[r],r--;
		else
			ans+=(c[l]!=c[r])*cnt[l],l++,r--;
	}cout<<ans;
	return 0;
}
