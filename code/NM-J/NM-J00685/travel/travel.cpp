#include<bits/stdc++.h>
using namespace std;
int c1,c2,n,m;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    n=(s1[0]-'0')*10+(s1[1]-'0');
    m=(s2[0]-'0')*10+(s2[1]-'0');
//	cout<<n;
    if(c1!=c2){
        cout<<"0000";
    }else if(n!=m){
    	cout<<"1000";
	}else if(!((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))){
		cout<<"1100";
	}else if(s1[2]-s2[2]!=1&&s2[2]-s1[2]!=1){
		cout<<"1110";
	}else cout<<"1111";
	return 0;
}
