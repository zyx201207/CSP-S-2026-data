#include<bits/stdc++.h>
using namespace std;
int x[6]={1,1,1,2,0,2};
string c1,s1,c2,s2,r1,r2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	r1=s1[0]+s1[1],r2=s2[0]+s2[1];
	if(c1==c2){
		cout<<1;
		if(r1==r2){
			cout<<1;
			if(x[s1[2]-'A']==x[s2[2]-'A']){
				cout<<1;
				if(max(s1[2],s2[2])-min(s1[2],s2[2])==1||min(s1[2],s2[2])=='D'&&max(s1[2],s2[2])=='F')cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
//有小坑，果然是Trick 
