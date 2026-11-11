#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;	
	int mx=-INT_MAX,x=-1,ans=-1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	ans=max(ans,a[i]);
	    for(int j=1;j<i;j++){
	    	LL pd=abs(a[i]-a[j]);
	        if(pd%2==0&&pd%4==0||pd==1||pd==2){
	        	x=min(a[i],a[j]);
	        	mx=max(x,mx); 
			} 
		}
	}
	if(m==1) cout<<ans;
	else cout<<mx;
	return 0;
}
