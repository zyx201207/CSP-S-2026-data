#include <bits/stdc++.h>
using namespace std;
int a[10];
int p,q;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {
            cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){

         cout<<"000";
         return 0;
        }
    }
    cout<<"1";
    a[s1[2]-'A'+1]++;
    a[s2[2]-'A'+1]++;
    for(int i=1;i<=3;i++){
        if(a[i]==1) p++;
    }
    for(int i=4;i<=5;i++){
        if(a[i]==1) q++;
    }
    if(p==2){
        if(abs(s2[2]-s1[2])==1){
            cout<<"11";
        }
        else cout<<"10";

    }
    else if(q==2) cout<<"11";
    else{
        cout<<"00";
    }
    return 0;
}
