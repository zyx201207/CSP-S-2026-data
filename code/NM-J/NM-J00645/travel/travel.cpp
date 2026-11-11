#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1;
    string c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==s1)
    {
        cout<<"0";
    }
    else
    {
        cout<<"1";
    }
    if(c2[0]&&c2[1]==s2[0]&&s2[1])
    {
        cout<<"0";
    }
    else
    {
        cout<<"1";
    }
    if(c2[3]=="A"||"B"||"C"&&s2[3]=="A"||"B"||"C")
    {
        cout<<"0";
    }
    else
    {
        cout<<"1";
    }
    if(c2[3]-S2[3]==1&&S2[3]-C2[3]==1)
    {
        cout<<"0";
    }
    else
    {
        cout<<"1";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
