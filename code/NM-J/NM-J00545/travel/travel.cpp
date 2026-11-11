#include<bits/stdc++.h>
using namespace std;
int main(){
    /*ios::sync.stdio;
    cin.tie(0);
    cout.tie(0);*/
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    for(int i=0;i<=1;i++){
        s1[i]=int(s1[i]-'0');
        s2[i]=int (s2[i]-'0');
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')){
            cout<<1;
            if(s1[2]>=s2[2]){
                if((s1[2]-s2[2]<=1)){
                   cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                if((s2[2]-s1[2])<=1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }

        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0<<0<<0;
    }
    return 0;
}
