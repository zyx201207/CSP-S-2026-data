#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+="1";
	else ans+="0";
	string z1;
	z1+=s1[0]+s1[1];
	string z2;
	z2+=s2[0]+s2[1];
	char w1,w2;
	w1=s1[2],w2=s2[2];
	if(w1=='F') w1='E';
	if(w2=='F') w2='E';
	int ww1,ww2;
	if(z1==z2&&c1==c2) {
		ans+="1";
		if(w1=='A'||w1=='B'||w1=='C') ww1=0;
		else ww1=1;
		if(w2=='A'||w2=='B'||w2=='C') ww2=0;
		else ww2=1;
		if(ww1==ww2) ans+="1";
		else ans+="0";
	}
	else ans+="00";
	if(abs(w1-w2)==1&&c1==c2&&z1==z2&&ww1==ww2) ans+="1";
	else ans+="0";
	cout<<ans;
	return 0;
}
