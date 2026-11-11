#include<bits/stdc++.h>
using namespace std;
string a,c,b,d;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        ans="0000";
        cout<<ans;
        return 0;
    }else ans+="1";
    if(b[0]==d[0]&&b[1]==d[1]) ans+="1";
    else {
		ans+="000";
		cout<<ans;
		return 0;
	}
    if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
        ans+="1";
        if(abs(b[2]-d[2])==1){
            ans+="1";
        }else{
			ans+="0";
        }
    }else if((b[2]=='D'&&d[2]=='F') || (b[2]=='F'&&d[2]=='D')){
        ans+="11";
    }else{
        ans+="00";
    }
    cout<<ans;
    //ni ying gai guo guan!!(ba)
    return 0;
}
