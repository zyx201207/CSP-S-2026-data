#include<bits/stdc++.h>
using namespace std;
bool che(string x1,string x2)
{
    if(x1 == x2) return true;
    else return false;
}
bool pai(string x1,string x2)
{
    char s1,s2,s3,s4;
    s1 = x1[0];
    s2 = x1[1];
    s3 = x2[0];
    s4 = x2[1];
    if(s1 == s3&&s2 == s4) return true;
    else return false;
}
bool wei(string x1,string x2)
{
    char s1,s2;
    s1 = x1[2];
    s2 = x2[2];
    int a1 = s1;
    int a2 = s2;
    if(a1>=65&&a1<=67&&a2>=65&&a2<=67) return true;
    else if(a1>=68&&a1<=70&&a2>=68&&a2<=70) return true;
    else return false;
}
bool lin(string x1,string x2)
{
    char s1,s2;
    s1 = x1[2];
    s2 = x2[2];
    int a1 = s1;
    int a2 = s2;
    if(a1+1 == a2||a2+1 == a1) return true;
    else return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(che(c1,c2))
    {
        cout<<"1";
        if(pai(s1,s2))
        {
            cout<<"1";
            if(wei(s1,s2))
            {
                cout<<"1";
                if(lin(s1,s2))
                    cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
