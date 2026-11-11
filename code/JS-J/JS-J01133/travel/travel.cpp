#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) {
        cout<<"0000";
        return 0;
    }
    string t1,t2;
    t1+=s1[0],t1+=s1[1];
    t2+=s2[0],t2+=s2[1];
    if(t1!=t2){
        cout<<"1000";
        return 0;
    }
    char t3,t4;
    t3=s1[2],t4=s2[2];
    if(abs(t3-t4)>2||(t3=='C'&&t4=='D')||(t3=='C'&&t4=='F')||(t3=='B'&&t4=='D')){
        cout<<"1100";
        return 0;
    }
    if(abs(t3-t4)>1||(t3=='C'&&t4=='D')){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
