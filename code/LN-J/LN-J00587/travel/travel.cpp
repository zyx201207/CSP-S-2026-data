#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);


    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int w1,w2;
    w1=(b[0]-'0')*10+(b[1]-'0');
    w2=(d[0]-'0')*10+(d[1]-'0');
    char c1,c2;
    c1=b[2],c2=d[2];
    if(a==c)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(w1==w2)cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(c1=='C'&&c2=='D')
    {
        cout<<"00";
        return 0;
    }
    if(c1=='D'&&c2=='C')
    {
        cout<<"00";
        return 0;
    }
    if(((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C'))||((c1=='D'||c1=='F')&&(c2=='D'||c2=='F')))cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(((c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))||(((c1=='A'||c1=='B')&&(c2=='A'||c2=='B')))||((c1=='B'||c1=='C')&&(c2=='B'||c2=='C')))cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
