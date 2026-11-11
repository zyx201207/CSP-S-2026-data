#include<bits/stdc++.h>
using namespace std;
int n,k;

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
    	cin>>n>>k;
    	for(int i=1,_;i<n;i++)
    		cin>>_>>_;
    	int a[4]={0,n/3,n/3,n/3};
    	for(int i=1;i<=k-a[1]*3;i++)
    		a[i]++;
    	k-=2;
    	for(int i=1;i<=k-a[1]*3;i++)
    		if(k) k--,a[i]--;
    	if(!k) cout<<max(a[1],max(a[2],a[3]))<<'\n';
		else cout<<a[1]-k/3<<'\n';
	}
    return 0;
}
