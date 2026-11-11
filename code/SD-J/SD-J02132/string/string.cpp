#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
char s[N];
int cnt[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		cnt[i] = a,s[i]=c;
	}
	int l=1,r=n;
	int ans = 0;
	while(l<r){
		int num1 = cnt[l],num2 = cnt[r];
		if(s[l]==s[r]){
			if(cnt[l]>=cnt[r]){
				cnt[l]-=cnt[r],cnt[r]=0;
			}
			else cnt[r]-=cnt[l],cnt[l]=0;
			if(cnt[l]==0) l++;
			if(cnt[r]==0) r--;
		}
		else{
			ans+=abs(min(cnt[l],cnt[r]));
			if(cnt[l]>=cnt[r]){
				cnt[l]-=cnt[r],cnt[r]=0;
			}
			else cnt[r]-=cnt[l],cnt[l]=0;
			if(cnt[l]==0) l++;
			if(cnt[r]==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
