#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans="";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			ans+='1';
			bool x,y;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				x=0;
			}
			else{
				x=1;
			}
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				y=0;
			}
			else{
				y=1;
			}
			if(x==y){
				ans+='1';
				if(x==0){
					char mi=min(b[2],d[2]),ma=max(b[2],d[2]);
					if((mi=='A'&&ma=='B')||(mi=='B'&&ma=='C')){
						ans+='1';
					}
				}
				else{
					char mi=min(b[2],d[2]),ma=max(b[2],d[2]);
					if(mi=='D'&&ma=='F'){
						ans+='1';
					}
				}
			}
		}
	}
	while(ans.size()<4){
		ans+='0';
	}
	cout<<ans<<'\n';
	return 0;
}