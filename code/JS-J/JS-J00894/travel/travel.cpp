#include<bits/stdc++.h>
using namespace std;
int main(){
    string c1,s1,c2,s2;
    bool b1 = true,b2 = true;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2) cout<<1;
    else{
        b1 = false;
        cout<<0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1] && b1) cout<<1;
    else{
        b2 = false;
        cout<<0;
    }
    if( (((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C')) || ((s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'D' && s2[2] <= 'F'))) && b2 && b1) cout<<1;
    else cout<<0;
    if(abs((int)s1[2] - (int)s2[2]) == 1 && !( (s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'C' && s2[2] == 'D') ) && b2 && b1) cout<<1;
    else cout<<0;
    cout<<"\n";
    return 0;
}
