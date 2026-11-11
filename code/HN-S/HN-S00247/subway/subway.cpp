#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a;
long long ans,ans1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>a;
		ans1+=a;
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= 2*k;j++){
			cin>>a;
			if(j%2==0) ans+=a;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<min(ans,ans1)<<endl;
	}
	return 0;
}
