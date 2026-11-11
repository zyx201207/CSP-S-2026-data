#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a!=b)cout<<"0000";
    else{
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')){
                cout<<1;
                if(abs(s1[2]-s2[2]))cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    return 0;
}
