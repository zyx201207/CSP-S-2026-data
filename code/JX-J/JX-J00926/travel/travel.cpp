#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    s1=" "+s1;
    s2=" "+s2;
    if(c1!=c2) {cout<<"0000";return 0;}
    else{
        int q1=int((s1[1]-'0'))*10+int((s1[2]-'0'));
        int q2=int((s2[1]-'0'))*10+int((s2[2]-'0'));
        if(q1!=q2){cout<<"1000";return 0;}
        else{
            char w1=char(s1[3]);
            char w2=char(s2[3]);
            cout<<w1<<" "<<w2<<'\n';
            if((w1=='F' || w1=='D')&&(w2!='F' && w2!='D')){cout<<"1100";return 0;}
            else if((w1=='A' || w1=='B' || w1=='C')&&(w2!='A' && w2!='B' && w2!='C')){cout<<"1100";return 0;}
            else{
                if(w1=='A' && w2!='B'){cout<<"1110";return 0;}
                else if(w1=='B' && (w2!='A'|| w2!='c')){cout<<"1110";return 0;}
                else if(w1=='C' && w2!='B'){cout<<"1110";return 0;}
                else if(w1=='D' && w2!='F'){cout<<"1110";return 0;}
                else if(w1=='F' && w2!='D'){cout<<"1110";return 0;}
                else cout<<"1111";
            }
        }
    }
    return 0;
}
