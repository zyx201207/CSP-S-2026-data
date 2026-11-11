#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
                cout<<"1";
                if(s1[2]>='A'&&s1[2]<='C'){
                    if(max(s1[2],s2[2])-min(s1[2],s2[2])==1&&max(s1[2],s2[2])!='D'){
                        cout<<"1";
                        return 0;
                    }
                    else{
                        cout<<"0";
                        return 0;
                    }
                }
                else if(s1[2]>='D'&&s1[2]<='F'){
                    if(max(s1[2],s2[2])-min(s1[2],s2[2])==2&&min(s1[2],s2[2])!='B'){
                        cout<<"1";
                        return 0;
                    }
                    else{
                        cout<<"0";
                        return 0;
                    }
                }
                else{
                    cout<<"0";
                    return 0;
                }

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
