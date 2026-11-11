#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,d1,d2,d3,u,v,m,x1,x2;
vector<int>f[1000010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
	    while(T--){
    	cin>>n>>k;
    	if(k>=n){
    		cout<<0;
    		continue;
		}
    	for(int i=1;i<=n;i++)f[i].clear();
    	for(int i=1;i<n;i++){
    		cin>>u>>v;
    		f[u].push_back(v);
    		f[v].push_back(u);
		}
		m=(n-1)/2;
    	if(k==1){
    		cout<<m/2+m%2;
    		continue;
		}
    	else if(k>=m){
    		cout<<1;
    		continue;
		}
		else if(k==2){
			cout<<min(m-m/2-m%2,m/2+m%2);
		    continue;
		}
		else{
			x1=m/2;
			x2=x1+(m-x1)/2;
			d1=x1;
			d2=x2-x1;
			d3=m-x2;
			for(int i=1;i<=k;i++){
				if(d1==max(d1,max(d2,d3)))d1--;
				else if(d2==max(d1,max(d2,d3)))d2--;
				else if(d3==max(d1,max(d2,d3)))d3--;
			}
		}
	    cout<<max(d1,max(d2,d3));
	}
}
/*

*/
