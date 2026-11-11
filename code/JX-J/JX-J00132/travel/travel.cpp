#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a1=0,a2=0,a3=0,a4=0;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2)a1=1;
    else{
        cout<<"0000";
        return 0;
    }

    int s1_seat=0,s2_seat=0;
    char s1_word,s2_word;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='0' && s1[i]<='9'){
            s1_seat=s1_seat*10+s1[i]-'0';
        }
        if(s1[i]>='A' && s1[i]<='F'){
            s1_word=s1[i];
        }
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]>='0' && s2[i]<='9'){
            s2_seat=s2_seat*10+s2[i]-'0';
        }
        if(s2[i]>='A' && s2[i]<='F'){
            s2_word=s2[i];
        }
    }

    if(s1_seat==s2_seat){
        a2=1;
        if(s1_word>='A' && s1_word<='C' && s2_word>='A' && s2_word<='C') {
            a3=1;
            if(s1_word=='A' && s2_word=='B' || s2_word=='A' && s1_word=='B' || s1_word=='B' && s2_word=='C' || s2_word=='B' && s1_word=='C'){
                a4=1;
            }
        }
        else if(s1_word>='D' && s1_word<='F' && s2_word>='D' && s2_word<='F'){
            a3=1;
            if(s1_word=='D' && s2_word=='F' || s2_word=='D' && s1_word=='F'){
                a4=1;
            }
        }
    }
    if(a4==1)cout<<1111;
    else if(a3==1)cout<<1110;
    else if(a2==1)cout<<1100;
    else cout<<1000;

    return 0;
}
