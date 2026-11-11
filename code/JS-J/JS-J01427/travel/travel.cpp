#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int x=(a[0]-'0')*10+a[1]-'0';
    int y=(c[0]-'0')*10+c[1]-'0';
    if(x==y)
    {
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    int m=(b[0]-'0')*10+b[1]-'0';
    int n=(d[0]-'0')*10+d[1]-'0';
    if(m==n)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    int t=b[2]-'A';
    int p=d[2]-'A';
    if(t<3&&p<3)
    {
        cout<<"1";
    }
    else if(t>2&&p>2)
    {
        cout<<"11";
        return 0;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(t-p<=1)
    {
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
