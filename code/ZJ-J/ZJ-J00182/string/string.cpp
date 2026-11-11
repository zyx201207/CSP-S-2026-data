#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],i,sum,pre[200005],ans;
char s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]+pre[i-1];
		cin>>s[i];
	}
	for(i=1;pre[i]<=pre[n]/2ll;i++){
		int x=pre[n]-pre[i]+1;
		int y=pre[n]-pre[i-1];
		int l=lower_bound(pre+1,pre+n+1,x)-pre;
		int r=upper_bound(pre+1,pre+n+1,y)-pre;
		if(l==r-1){
			if(s[i]!=s[l])ans+=y-x+1;
		}else{
			if(s[l]!=s[i])ans+=pre[l+1]-x;
			if(s[r-1]!=s[i])ans+=y-pre[r-1];
			for(int j=l+1;j<r-1;j++){
				if(s[i]!=s[j])ans+=a[j];
			}
		}
	}if(pre[i-1]+1<sum/2ll){
		int x=pre[n]-(pre[i]-pre[i]-(sum+1)/2ll)*2ll;
		int y=pre[n]-pre[i-1];
		int l=lower_bound(pre+1,pre+n+1,x)-pre;
		int r=upper_bound(pre+1,pre+n+1,y)-pre;
		if(l==r-1){
			if(s[i]!=s[l])ans+=y-x+1;
		}else{
			if(s[l]!=s[i])ans+=pre[l+1]-x;
			if(s[r-1]!=s[i])ans+=y-pre[r-1];
			for(int j=l+1;j<r-1;j++){
				if(s[i]!=s[j])ans+=a[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
