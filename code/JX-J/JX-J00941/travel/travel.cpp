#include <bits/stdc++.h>
using namespace std;
long long c1,c2;
char a[10],b[10],s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>a[1]>>a[2]>>s1;
    cin>>c2>>b[1]>>b[2]>>s2;
    if(c1==c2){cout<<1;
    }else cout<<0;
    if(c1==c2&&a[1]==b[1]&&a[2]==b[2]){cout<<1;
    }else cout<<0;
    if(c1==c2&&a[1]==b[1]&&a[2]==b[2]){
        if((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')) cout<<1;
        else{
            if((s2=='B'&&(s1=='A'||s1=='C'))||(s1=='B'&&(s2=='A'||s2=='C')) ) cout<<1;
            else cout<<0;
        }
    }else cout<<0;
    if(c1==c2&&a[1]==b[1]&&a[2]==b[2]){
      if((s1=='A'&&s2=='B')||(s1=='B'&&(s2=='A'||s2=='C'))||(s1=='C'&&s2=='B')||(s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')) cout<<1;
      else{
          if((s2=='A'&&s1=='B')||(s2=='B'&&(s1=='A'||s1=='C'))||(s2=='C'&&s1=='B')||(s2=='D'&&s1=='F')||(s2=='F'&&s1=='D')) cout<<1;
          else cout<<0;
      }
    }else cout<<0;

  return 0;
}
