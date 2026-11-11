#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	cout<<c1<<" "<<c1;
	if(c1==s1){
		cout<<"1";
		char q1=c2[0],q2=c2[1];
		char p1=s2[0],p2=s2[1];
		if(p1==q1 and p2==q2){
			cout<<"1";
			char p=c2[2],q=s2[2];
			if((p>='D' and q>='D') or (p<='C' and q<='C')){
				cout<<"1";
				if(abs(p-q)==1)cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
