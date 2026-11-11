#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    for(int i=1;i<=10;i++){
        cin>>s[i];
    }
    bool flag=0;
    if(s[1]==s[6]&&s[2]==s[7]){
    cout<<1;
    }else{
    cout<<0<<0<<0<<0;
    return 0;
    }
    if(s[3]==s[8]&&s[4]==s[9]){
    cout<<1;
    }else{
    cout<<0;
    flag=1;
    }
    if(flag==0){
        if((s[5]=='A'||s[5]=='B'||s[5]=='C')&&(s[10]=='A'||s[10]=='B'||s[10]=='C')){
			cout<<1;
			}else if((s[5]=='D'||s[5]=='E')&&(s[10]=='D'||s[10]=='E')){
			cout<<1;
			}else{
			cout<<0;
			}
        }else{
        cout<<0<<0;
        return 0;
        }
	if((s[5]=='A'&&s[10]=='B')||(s[5]=='B'&&s[10]=='A')||(s[5]=='B'&&s[10]=='C')||(s[5]=='C'&&s[10]=='B')||(s[5]=='D'&&s[10]=='E')||(s[5]=='E'&&s[10]=='D')){
	cout<<1;
	}else{
	cout<<0;
	}
    return 0;
}
