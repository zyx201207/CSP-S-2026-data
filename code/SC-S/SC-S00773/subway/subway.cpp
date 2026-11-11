#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,w;i<=m;i++){
		cin>>w;
		ans+=w;
	}
    while(q--){
    	cout<<ans<<"\n";
    }
	return 0;
}