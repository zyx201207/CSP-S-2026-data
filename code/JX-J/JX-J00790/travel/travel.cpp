#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(((s1[2]>='A'&&s1[2]<='C')&&
            (s2[2]>='A'&&s2[2]<='C'))||(
            (s1[2]=='D'||s1[2]=='F')&&
            (s2[2]=='D'||s2[2]=='F'))){
                if(abs((int)s1[2]-s2[2])==1){
                    cout<<"1111";
                }
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
}

    // he yi wei
    // freopen(".in","r",stdout);
    // freopen(".out","w",stdin);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    // freopen(".in","r",stdin);
    // freopen(".uot","w",stdout);
    // freopen(".in","w",stdin);
    // freopen(".out","r",stdout);
    // froepen(".in","r",stdin);
    // froepen(".ans","w",stdout);
    // shang mian de shi mi huo xing wei de 
    // xi wang jin nian JX you
    //
    // lao sha zi ba dian san shi yi le zen 
    // me hai bu fa mi ma tiao ma le ge bi de
    // jing ran rang wo shao kao hao ji fen zhong 
    // ma de zen me hou mian de kao chang ke yi 
    // xian xia zai shi ti
    // cao ta ma de zen me 8:35 le cai ke yi xia
    // zai shi ti
    // suan le fan zheng 300 pts jiu xing le

    