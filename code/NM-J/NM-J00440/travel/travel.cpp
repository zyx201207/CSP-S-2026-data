#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>s1>>s2>>c1>>c2;
    char b=s2[2],d=c2[2];
    if(s1==c1){
        cout<<1;
        int s=(s2[0]+s2[1]-'0'),c=(c2[0]+c2[1]-'0');
        if(s==c){
            cout<<1;
        }else{
            cout<<0<<0<<0;
            return 0;
        }
        if((d=='D'||d=='F')&&(b=='D'||b=='F')){
            cout<<1<<1;
            return 0;
        }else{
            if(b!='D'&&b!='F'&&d!='D'&&d!='F'){
                cout<<1;
            }else{
                cout<<0<<0<<0;
                return 0;
            }
            if((d+1==b||b+1==d)){
                if(b!='C'&&d!='D'&&b!='D'&&b!='C'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
