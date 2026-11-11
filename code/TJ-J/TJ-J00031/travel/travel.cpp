#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2;
string s1,s2;
string ans;
string n1,n2;
char z,w;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n1+=s1[0];
	n1+=s1[1];
	n2+=s2[0];
	n2+=s2[1];
	z=s1[2];
	w=s2[2];
	if(c1==c2){
		ans+='1';
		if(n1==n2){
			ans+='1';
			if((z>='A'&&z<='C'&&w>='A'&&w<='C')||(z>='D'&&w>='D')){
				ans+='1';
				if(abs(z-w)==1&&(z+w!=('C'+'D'))){
					ans+='1';
				}
				else{
					ans="1110";
				}
			}
			else{
				ans="1100";
			}
		}
		else{
			ans="1000";
		}
	}
	else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
