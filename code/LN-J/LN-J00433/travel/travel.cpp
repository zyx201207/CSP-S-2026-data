#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            int a=0,b=0,c=0,d=0,f=0;
            if(s1[2]=='A')a++;
            if(s1[2]=='B')b++;
            if(s1[2]=='C')c++;
            if(s1[2]=='D')d++;
            if(s1[2]=='F')f++;
            if(s2[2]=='A')a++;
            if(s2[2]=='B')b++;
            if(s2[2]=='C')c++;
            if(s2[2]=='D')d++;
            if(s2[2]=='F')f++;
            if(a+b+c==2&&(a==1&&b==1 || b==1&&c==1 || a==1&&c==1)){
                cout<<1;
                if(a==1&&b==1||b==1&&c==1){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else if(d+f==2&&d==1&&f==1){
                cout<<1;
                if(d==1&&f==1){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
