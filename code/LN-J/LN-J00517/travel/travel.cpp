#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string a,a1,b,b1;
    cin>>a>>a1>>b>>b1;
    if(a==b){
        cout<<1;
        int ap=(a1[0]-'0')*10+(a1[1]-'0'),bp=(b1[0]-'0')*10+(b1[1]-'0');
        if(ap==bp){
            cout<<1;
            if((a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C')||(a1[2]>='D'&&a1[2]<='E'&&b1[2]>='D'&&b1[2]<='E')){
                cout<<1;
                if(abs(a1[2]-b1[2])==1){
                    cout<<1;
                }
                else cout<<0;
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
