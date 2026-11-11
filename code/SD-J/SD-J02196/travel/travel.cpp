#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y)*y)
using namespace std;
void solve(){
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<"0000"; 
	}else if(c2[0]!=c4[0]||c2[1]!=c4[1]){
		cout<<"1000";
	}else if(!(('A'<=c2[2]&&c2[2]<='C')&&('A'<=c4[2]&&c4[2]<='C'))&&!(('D'<=c2[2]&&c2[2]<='E')&&('D'<=c4[2]&&c4[2]<='E'))){
		cout<<"1100";
	}else if((char)(c2[2]+1)!=c4[2]&&c2[2]!=(char)(c2[2]+1)){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
