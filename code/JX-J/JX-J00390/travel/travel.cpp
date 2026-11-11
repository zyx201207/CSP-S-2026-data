#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else{
        cout<<"0000"<<"\n";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
    else{
        cout<<"000"<<"\n";
        return 0;
    }
    if((s1[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&s1[2]=='D')){
        cout<<"11"<<"\n";
        return 0;
    }
    else{
        if((s1[2]=='D'&&s2[2]=='C')||(s2[2]=='D'&&s1[2]=='C'))
        {
            cout<<"00"<<"\n";
            return 0;
        }
        else if(abs(s1[2]-s2[2])==1)
        {
            cout<<"11"<<"\n";
            return 0;
        }
        else cout<<"10"<<"\n";
        return 0;
    }
    return 0;
}
