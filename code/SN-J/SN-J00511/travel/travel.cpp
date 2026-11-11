#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char z1,z2;
int xs1,xs2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int lens1=s1.size();
	int lens2=s2.size();
	for(int i=0;i<lens1;i++){
		if(!(s1[i]>='0'&&s1[i]<='9')){
			z1=s1[i];
			break;
		}
		xs1*=10;
		xs1+=s1[i]-'0';
	}
	for(int i=0;i<lens2;i++){
		if(!(s2[i]>='0'&&s2[i]<='9')){
			z2=s2[i];
			break;
		}
		xs2*=10;
		xs2+=s2[i]-'0';
	}
	if(xs1==xs2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((z1=='F'||z1=='D')&&(z2=='F'||z2=='D')){
		cout<<"11";
	}else if((z1=='A'||z1=='B'||z1=='C')&&(z2=='A'||z2=='B'||z2=='C')){
		cout<<1;
		if(z1==z2+1||z1+1==z2){
			cout<<1;
		}else cout<<0;
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
