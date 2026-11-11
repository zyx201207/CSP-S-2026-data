#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool a=0;
    for(int i=0;i<=1;i++)
    {
        if(c1[i]!=c2[i]) a=1;
    }
    if(a)
    {
        cout << "0000\n";
        return 0;
    }
    else cout << "1";
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i]) a=1;
    }
    if(a)
    {
        cout << "000\n";
        return 0;
    }
    else cout << "1";
    if((s1[2]>= 'A' && s1[2]<= 'C')&&(s2[2]>= 'A' && s2[2]<= 'C')) a=0;
    else if((s1[2]>= 'D' && s1[2]<= 'E')&&(s2[2]>= 'D' && s2[2]<= 'E')) a=0;
    else a=1;
    if(a)
    {
        cout << "00\n";
        return 0;
    }
    else cout << "1";
    if(abs(s2[2] - s1[2])>1) a=1;
    if(a) cout << "0\n";
    else cout << "1\n";
    return 0;
}
