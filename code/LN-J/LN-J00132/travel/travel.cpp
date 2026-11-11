#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2,q1,q2,q;
char a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>a1>>c2>>s2>>a2;
    q1=int(a1),q2=int(a2);
    q=int('D');
    if(c1==c2)
        if(s1==s2){
            if(q1<q&&q2<q)
                if(abs(q1-q2)==1)cout<<"1111";
                else cout<<"1110";
            else if(q1>=q&&q2>=q)cout<<"1111";
            else cout<<"1100";
        }
        else cout<<"1000";
    else cout<<"0000";
    return 0;
}
