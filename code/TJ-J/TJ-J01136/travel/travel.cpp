#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int h1,h2;
int ans;
bool lr;
void a(){
	if(c1==c2) ans++;
	else return ;
	if((s1[0]==s2[0])&&(s1[1]==s2[1])) ans++;
	else return ;
	if(h1<=3&&h2<=3){
		ans++;
		lr=false;
	}
	else if(h1>3&&h2>3){
		ans++;
		lr=true;
	}
	else return ;
	if(lr) ans++;
	else if(abs(h1-h2)<=1){
		ans++;
	}
}
void b(){
	if(ans==0) cout<<"0000";
	if(ans==1) cout<<"1000";
	if(ans==2) cout<<"1100";
	if(ans==3) cout<<"1110";
	if(ans==4) cout<<"1111";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	h1=s1[2]-'A'+1;
	h2=s2[2]-'A'+1;
	a();
	b();
	return 0;
} 
