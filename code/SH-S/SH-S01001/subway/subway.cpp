#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,p,a[100005],ans;
int main(){
	freopen("subway.in",stdin);
	freopen("subway.out",stdout);
	cin>>c>>n>>m>>d>>q;
	while(q--){
		for(int i=1;i<=m;i++){
			cin>>a[i];
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
}
