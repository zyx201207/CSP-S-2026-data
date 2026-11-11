#include<bits/stdc++.h>
using namespace std;
string ans;
int g1[3],g2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i = 0;i<=1;i++){
		g1[i]=s1[i]-'0';
		g2[i]=s2[i]-'0';
	}
	int G1=g1[0]*10+g1[1],G2=g2[0]*10+g2[1];
	if(c1==c2){
		ans+='1';
		if(G1==G2){
			ans+='1';
			if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C'){
				ans+='1';
				if(abs(int(s1[2]-s2[2]))==1){
					ans+='1';
				}
				else{
					ans+='0';
				}
			}
			else{
				ans+='0';
				ans+='0';
			}
		}
		else{
			ans+='0';
			ans+='0';
			ans+='0';
		}
	}
	else{
		ans+='0';
		ans+='0';
		ans+='0';
		ans+='0';
	}
	cout<<ans;
	return 0;
}

