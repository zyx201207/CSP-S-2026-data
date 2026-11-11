#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
bool k[4]={false,false ,false,false};
int s11,s22;
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
s11=(int)s1[2];
s22=(int)s2[2];
if(c1==c2){
    k[0]=!k[0];
  if(s1[0]==s2[0]&&s1[1]==s2[1]){
        k[1]=!k[1];
        if((s11>=65&&s11<=67&&s22>=65&&s22<=67)||(s11>=68&&s11<=69&&s22>=68&&s22<=69)){
                k[2]=!k[2];
                if(max(s11,s22)-min(s11,s22)==1)
                    k[3]=!k[3];
        }
  }
}
for(int i=0;i<=3;i++){
    cout<<k[i];
}

return 0;
}
