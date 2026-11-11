#include<bits/stdc++.h>
using namespace std;
int qz(string s){
    int sum=0;
    if(s[0])sum=10;
    if(s[1]=='1')sum+=1;
    else if(s[1]=='2')sum+=2;
    else if(s[1]=='3')sum+=3;
    else if(s[1]=='4')sum+=4;
    else if(s[1]=='5')sum+=5;
    else if(s[1]=='6')sum+=6;
    else if(s[1]=='7')sum+=7;
    else if(s[1]=='8')sum+=8;
    else if(s[1]=='9')sum+=9;
    return sum;
}
char qz2(string s){
    char c;
    c=s[2];
    return c;
}
int main(){
 //   freopen("travel.in","r",stdin);
  // freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int a1=qz(a),a2=qz(c),b1=qz(b),b2=qz(d);
    char s1=qz2(b),s2=qz2(d);
    if(a1!=a2)cout<<"0000";
    else {
        cout<<1;
        if(b1!=b2)cout<<"000";
        else{
                cout<<1;
            if(s1=='A'||s1=='B'||s1=='C'){
                if(s2=='A'||s2=='B'||s2=='C'){
                    cout<<1;
                    if(s1+2==s2||s1-2==s2)cout<<0;
                    else cout<<1;
                }else cout<<"00";
            }else{
                if(s2=='A'||s2=='B'||s2=='C')cout<<"00";
                else {
                    cout<<"11";
                }
            }
        }
    }
    return 0;
}
