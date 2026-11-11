#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin >> s1 >> s2 >> c1 >> c2;
    bool b1 = 0,b2 = 0;
    int a=0,b= 0,c=0,d=0;
    if(s1 == c1){
        a = 1;
        b1 = 1;
    }
    int x1 = (s2[0]-'0')*10+(s2[1]-'0');
    int x2 = (c2[0]-'0')*10+(s2[1]-'0');
    if(b1){
        if(x1 == x2){
           b = 1;
           b2 = 1;
        }
    }
    char ch1 = s2[2],ch2 = c2[2];
    int cnt1 = 0,cnt2 = 0;
    if(b1&&b2){
          if(ch1 <= 'C'){
             cnt1++;
          }
          else{
             cnt2++;
          }
          if(ch2 <= 'C'){
             cnt1++;
          }
          else{
             cnt2++;
          }
          if(cnt1 == 2||cnt2 == 2){
              c = 1;
          }
    }
    if((ch1 == 'D'&&ch2 == 'C')||(ch1 == 'C'&&ch2 == 'D')){
        d = 0;
    }
    else{
        if(ch1+1 == ch2||ch1-1 == ch2){
            d = 1;
        }
    }
    cout << a << b << c << d;
    return 0;
}
