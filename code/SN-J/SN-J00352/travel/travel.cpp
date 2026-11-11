#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int n=0,m=0,x=0,;
	cin >> a >> b >> c >>d;
	while(n<=4){
		if(a==c){
			cout << "1";
		}	
		for(int i=1;i<=a.size();i++){
			if(i==3){
				n=i;
			}
		}
		for(int j=1;j<=b.size();j++){
			if(j==3){
				m=j;
			}
		}
		if(m==n){
			cout << 1;
		}
		for(int i=1;i<=a.size();i++){
			if(i==4){
				x=i;
			}
		}
		for(int j=1;j<=b.size();j++){
			if(j==4){
				y=j;
			}
		}
	}
}
