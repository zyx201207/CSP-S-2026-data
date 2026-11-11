#include<bits/stdc++.h>
using namespace std;
string t1,t2,s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>t1>>s1>>t2>>s2;
    if(t1==t2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
                cout<<1;
                if(s1[2]>'C'||abs(s1[2]-s2[2])==1){
                    cout<<1;
                }
                else{
                    cout<<0<<endl;
                }
            }
            else{
                cout<<"00"<<endl;
            }
        }
        else{
            cout<<"000"<<endl;
        }
    }
    else{
        cout<<"0000"<<endl;
    }
    return 0;
}
