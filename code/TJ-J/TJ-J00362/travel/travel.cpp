#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,pai1="",pai2="",zimu1="",zimu2="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	pai1 = pai1+s1[0]+s1[1];
	pai2 = pai2+s2[0]+s2[1];
	zimu1 += s1[2];
	zimu2 += s2[2];
	if(pai1==pai2){
		cout<<1;
		if(((zimu1>='A'&&zimu1<='C')&&(zimu2>='A'&&zimu2<='C'))||((zimu2>='D'&&zimu2<='F')&&(zimu1>='D'&&zimu1<='F'))){
			cout<<1;
			if(zimu1+1==zimu2||zimu1-1==zimu2){
				cout<<1;
			}
		}
	}
	return 0;
}
