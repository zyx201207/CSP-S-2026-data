#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cc1=(c1[0]-'0')*10+(c1[1]-'0');
	int cc2=(c2[0]-'0')*10+(c2[1]-'0');
	bool flag=0;
	if(cc1==cc2){
        cout<<1;
	}else{
	    cout<<"0000";
	    return 0;
	}

	if(s1[1]==s2[1]){
         cout<<1;
	}else{
	    cout<<"000";
	    return 0;
	}

	if(s1[1]==s2[1]){
        if((s1[1]<='C'&&s2[2]<='C')||(s1[1]>'C'&&s2[2]>'C')){
            cout<<1;
            flag=1;
        }else{
            cout<<0;
        }
	}

	if(flag){
        int x1=s1[2]-'0';
        int x2=s2[2]-'0';
        if(max(x1,x2)-min(x1,x2)==1){
            cout<<1;
        }else{
            cout<<0;
        }
	}else{
	    cout<<0;
	}
	return 0;
}
