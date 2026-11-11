#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
        int t1=0,t2=0;
        t1+=s2[1]-'0',t2+=s4[1]-'0';t1+=(s2[0]-'0')*10;t2+=(s4[0]-'0')*10;
        if(t1==t2){
            cout<<1;
            int r=s2[2]-'A',x=s4[2]-'A';
            if((r<=2&&x<=2)||(r>2&&x>2)){
                cout<<1;
                if(abs(r-x)==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
