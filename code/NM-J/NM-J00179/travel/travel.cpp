#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,t1,t2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		cout<<1;
	}
	else cout<<0;
	t1+=s1[0];
	t1+=s1[1];
	t2+=s2[0];
	t2+=s2[1];
    if(t1==t2&&f1==1){
    	f2=1;
    	cout<<1;
	}
    else cout<<0;
    if(f2==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
    	f3=1;
    	cout<<1;
	}
    else cout<<0;
    if(f3&&abs(s1[2]-s2[2])==1){
    	cout<<1;
	}
    else cout<<0;
	return 0;
}
