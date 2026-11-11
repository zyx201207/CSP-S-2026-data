#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a1=s1[2]-'A'+1,a2=s2[2]-'A'+1;
    if(a1<a2) swap(a1,a2);
    if(a1==4) a1+=2;
    else if(a1==6) a1++;
    if(a2==4) a2+=2;
    else if(a2==6) a2++;
    if(c1[0]==c2[0] && c1[1]==c2[1]){
        cout<<1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            if(a1-a2<3){
                cout<<1;
                if(a1-a2==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}
