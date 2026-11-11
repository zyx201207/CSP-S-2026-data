#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bh,t;ll n,d;//岛屿数量、一次最多能飞的距离、
ll xy[2000010]={};//第i个岛屿的坐标
ll ans;
ll ma=4611686018000000000;
ll c=0;ll zh;
void f(int x,int e){
	if(x==e){
		if(ans<ma){
			ma=ans;
			c=1;
		}
		else if(ans==ma){
			c++;
		}
	}
	for(int i=1;i<=e-x;i++){
		if((xy[x+i]-xy[x])<=d){
			ans++;
			f(x+i,e);
			ans--;
		}
    }
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie();cout.tie();
	cin>>bh>>t;
	while(t--){
		zh=0;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
				cin>>xy[i];
		}
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(i==j)break;
				f(i,j);
				if(c==2){
					zh++;
				}
				c=0;ma=4611686018000000000;
			}
		}
		cout<<zh<<"\n";
	}
	
	return 0;
}
