#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,s1,x2,s2;
    cin>>x1>>s1>>x2>>s2;
    int a1=s1[2],a2=s2[2];
    if(x1==x2){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            if((max(a1,a2)-min(a1,a2)==1&&max(s1[2],s2[2])!='D')||
               (s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
                cout<<'1';
                if(max(a1,a2)-min(a1,a2)==1)
                    cout<<'1';
                else{
                    cout<<'0';
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
}
