#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


   string c1,s1,c2,s2;
   cin>>c1>>s1>>c2>>s2;
   string sr="";string sx="";
   sr=sr+s1[0]+s1[1];
   sx=sx+s2[0]+s2[1];
  // cout<<sr<<" "<<sx;
    if(c1==c2){
        cout<<1;
        if(sr==sx){
            cout<<1;
            if((s1[2]<='C'&& s2[2]<='C')||(s1[2]>='D'&& s2[2]>='D')){
                cout<<1;
                if(s1[2]<='C'&& s2[2]<='C'&&abs(s1[2]-s2[2]-'0')=='1'){
                    cout<<1;
                }
               else  if((s1[2]>='D'&& s2[2]>='D')){
                    cout<<1;
                }
                else cout<<0;
        }
        else cout<<0<<0;

    } else cout<<0<<0<<0;

}
else cout<<0<<0<<0<<0;





    return 0;


}
// 2 3

