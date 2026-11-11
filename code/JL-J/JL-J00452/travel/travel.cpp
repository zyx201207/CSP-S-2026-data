#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
    }else{
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')){
                cout<<1;
                if(max((int)s1[2],(int)s2[2])-min((int)s1[2],(int)s2[2])==1){
                    cout<<1<<'\n';
                }else{
                    cout<<0<<'\n';
                }
            }else{
                cout<<"00\n";
            }
        }else{
            cout<<"000\n";
        }
    }
    return 0;
}
