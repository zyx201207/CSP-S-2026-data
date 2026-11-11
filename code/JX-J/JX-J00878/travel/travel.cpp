#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,p1,p2,h1,h2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
        else{
            for(int i=0;i<4;i++) cout<<0;
            return 0;
        }
    p1=s1[0]+s1[1];
    p2=s2[0]+s2[1];
    if(p1==p2) cout<<1;
        else{
            for(int i=0;i<3;i++) cout<<0;
            return 0;
        }
    h1=s1[2];
    h2=s2[2];

    if(h1=="D"&&h2=="F" || h1=="A"&&h2=="B" || h1=="B"&&h2=="C" || h1=="A"&&h2=="C") cout<<1;
        else{
            swap(h1,h2);
             if(h1=="D"&&h2=="F" || h1=="A"&&h2=="B" || h1=="B"&&h2=="C" || h1=="A"&&h2=="C") cout<<1;
                else{
                    for(int i=0;i<2;i++) cout<<0;
                    return 0;
                }
        }
   if(h1=="D"&&h2=="F" || h1=="A"&&h2=="B" || h1=="B"&&h2=="C") cout<<1;
        else{
            swap(h1,h2);
             if(h1=="D"&&h2=="F" || h1=="A"&&h2=="B" || h1=="B"&&h2=="C") cout<<1;
                else cout<<0;
        }
    return 0;
}
