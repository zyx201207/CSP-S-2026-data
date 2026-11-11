#include<bits/stdc++.h>
using namespace std;
int t[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    int x=b[2]-'A'+1,y=d[2]-'A'+1;
    t[x]=1;
    t[y]=1;
    if(a==c)cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if(b[0]==d[0] && b[1]==d[1])
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if(t[1]+t[2]+t[3]==2 || t[4]+t[6]==2)
    {

        cout << 1;
    }
    else{
        cout << "00";
        return 0;
    }
    if(t[1]+t[2]==2 || t[2]+t[3]==2 || t[4]+t[6]==2)cout << 1;
    else cout << 0;
    return 0;
}
