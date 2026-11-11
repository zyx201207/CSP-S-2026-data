#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
		cout<<1;
		string t1=s1.substr(0,2),t2=s2.substr(0,2);
		if(t1==t2){
			cout<<1; 
			char a1=s1[2],a2=s2[2];
			if((a1<='C'&&a2<='C')||(a1>'C'&&a2>'C')){
				cout<<1;
				if(abs(a1-a2)==1)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else
			cout<<"000";
	}
    else cout<<"0000";
    return 0;
    
}
