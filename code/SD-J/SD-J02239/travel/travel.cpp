#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);cout.tie(nullptr);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	ll ap,bp;
	string aw="0",bw="0";
	aw+=a2[0],aw+=a2[1];
	bw+=b2[0],bw+=b2[1];
	ap=a2[2]-'A'+1;
	bp=b2[2]-'A'+1;
	if(a1==b1){
		ans+="1";
		if(aw==bw){
			ans+="1";
			if((ap<=3&&bp<=3)||(ap>=4&&bp>=4)){
				ans+="1";
				if((ap!=3&&bp!=4)&&(ap!=3&&bp!=4)&&abs(ap-bp)==1)
					ans+="1";
				else ans+="0";
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans="0000";
	cout<<ans;
	return 0;
}
//2026 10 31 8:47:
//T1 毒瘤大模拟样例通过 
