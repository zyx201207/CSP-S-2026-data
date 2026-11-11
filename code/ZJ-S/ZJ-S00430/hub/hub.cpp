#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int c,t,a[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		int x,y,sum=0;
		cin>>x>>y;
		for(int i=1;i<x;i++){
			int u,v;
			cin>>u>>v;
			if(abs(u-v)==1){
				sum++;
			}
		}
		if(x==1){
			cout<<1<<endl;
			continue;
		}
		if(sum>=y){
			cout<<sum%y+1<<endl;
		}else if(sum==y){
			cout<<sum<<endl;
		}else if(sum<y&&sum!=0){
			int xy=y;
			while(y>sum){
				y-=sum;
				if(y<=sum){
					break;
				}
			}
			if(y==1){
				if(x==xy+1){
					cout<<1<<endl;
					continue;
				}else{
					cout<<2<<endl;
					continue;
				}
			}
			cout<<sum/y<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
