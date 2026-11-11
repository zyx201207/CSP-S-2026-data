#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string g1,g2,c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(ll i=0;i<2;i++){
		g1+=s1[i];
		g2+=s2[i];
	}
	if(g1==g2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char a,b;
	a=s1[2]+1;
	b=s1[2]-1;
	//cout<<a<<endl<<b<<endl;
	if(g1==g2&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((a==s2[2]||b==s2[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
