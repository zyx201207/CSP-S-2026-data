#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bitset<4>ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]=1;
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))){
				ans[2]=1;
				if(abs(b[2]-d[2])==1){
					ans[3]=1;
				}
			}
		}
	}cout<<bool(ans[0])<<bool(ans[1])<<bool(ans[2])<<bool(ans[3]);
	return 0;
}
