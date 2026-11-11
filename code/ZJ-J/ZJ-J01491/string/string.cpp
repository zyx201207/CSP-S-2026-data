#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans;
char ch[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch[i];
	int l=1,r=n,cntl=a[1],cntr=a[n];
	while(l<r){
		if(ch[l]!=ch[r]){
			if(cntl<cntr)ans+=cntl,cntr-=cntl,l++,cntl=a[l];
			else if(cntl==cntr)ans+=cntl,l++,cntl=a[l],r--,cntr=a[r];
			else ans+=cntr,cntl-=cntr,r--,cntr=a[r];
		}
		else{
			if(cntl<cntr)cntr-=cntl,l++,cntl=a[l];
			else if(cntl==cntr)l++,r--,cntl=a[l],cntr=a[r];
			else cntl-=cntr,r--,cntr=a[r];
		}
	}
	cout<<ans;
	return 0;
//S1 pls S1 pls S1 pls S1 pls S1 pls S1 pls S1 pls S1 pls S1 pls S1 pls   
}