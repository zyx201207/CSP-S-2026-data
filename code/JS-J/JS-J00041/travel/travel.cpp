#include<bits/stdc++.h>
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    bool a = 0,b = 0,c = 0,d = 0;
    if(s1 == s2)
    {
        a = 1;
        if(c1[0] == c2[0] && c1[1] == c2[1])
        {
            b = 1;
            if((c1[2] <= 'C' && c2[2] <= 'C') || (c1[2] > 'C' && c2[2] > 'C'))
            {
                c = 1;
                if(abs(c1[2] - c2[2]) == 1) d = 1;                
            }   
        }  
    } 
    if(a) cout<<1;
    else cout<<0;
    if(b) cout<<1;
    else cout<<0;
    if(c) cout<<1;
    else cout<<0;
    if(d) cout<<1;
    else cout<<0;
    return 0;
}