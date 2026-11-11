#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,y,ans,a[200010];
char b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    x=1;y=n;
    while(x<=y){
    	if(a[x]>a[y]){
    		if(b[x]!=b[y])ans+=a[y];
    		a[x]-=a[y];y--;
		}
		else if(a[y]>a[x]){
    		if(b[x]!=b[y])ans+=a[x];
    		a[y]-=a[x];x++;
		}
		else{
    		if(b[x]!=b[y])ans+=a[x];
    		x++,y--;
		}
	}
	cout<<ans;
	return 0;
}
