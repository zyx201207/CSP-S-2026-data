#include <bits/stdc++.h>
using namespace std;
int a,b;
string x,y;
bool ans[5];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b){
		ans[1]=1;
		if(x[0]==y[0]&&x[1]==y[1]){
			ans[2]=1;
			if((x[2]<='C'&&y[2]<='C')||(x[2]>'C'&&y[2]>'C')){
				ans[3]=1;
				if(abs(int(x[2]-y[2]))==1) ans[4]=1;
			}
		}
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}