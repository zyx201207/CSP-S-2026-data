#include<bits/stdc++.h>
using namespace std;
string ca,cb,sa,sb,ans="0";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca[1]+ca[2]==cb[1]+cb[2]){
		if(sa[0]+sa[1]==sb[0]+sb[1]){
			if(sa[2]<=67&&sb[2]<=67||sa[2]>=68&&sb[2]>=68){
				if(abs(int(sa[2]-sb[2]))==1) ans="1111";
				else ans="1110";
			}
			else ans="1100";
		}
		else ans="1000";
	}
	else ans="0000";
	cout<<ans;
}