#include<bits/stdc++.h>
#define int long long 
const int N=2e5+10;
using namespace std;
string c1,z1,c2,z2;
void solve(){
	cin>>c1>>z1>>c2>>z2;
	if (c1==c2)cout<<"1";
	else cout<<"0";
	if (((c1==c2)&&(z1[0]==z2[0]&&z1[1]==z2[1])))cout<<"1";
	else cout<<"0";
	if ((c1==c2)&&(z1[0]==z2[0]&&z1[1]==z2[1])){
	if ((z1[2]-'A'<3&&z2[2]-'A'<3)||(z1[2]-'A'>=3&&z2[2]-'A'>=3))cout<<"1";
	else cout<<"0";
	}else cout<<"0";
	if (((z1[2]-'A'<3&&z2[2]-'A'<3)||(z1[2]-'A'>=3&&z2[2]-'A'>=3))&&((c1==c2)&&(z1[0]==z2[0]&&z1[1]==z2[1]))){
	if (abs((int)(z1[2]-z2[2]))==1)	cout<<"1";
	else cout<<"0";
	}else cout<<"0";
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
//	cin>>T;
	while (T--)solve();
	return 0;
} 
