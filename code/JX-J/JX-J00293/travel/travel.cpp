#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool flag = true;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
        cout <<'1';
    else
        {
            cout << '0';
            flag = false;
        }

    for(int i = 0;i <= 0;i++)
    {
        if(s1[0] == s2[0] && s1[1] == s2[1] &&flag == true)
            cout << '1';
        else
        {
            cout << '0';
            flag = false;
        }

    }
    for(int i = 2;i <=2;i++)
    {
        if((s1[i]<='C'&&s2[i]<='C'&&flag==true) || ((s1[i]>='D'&&s1[i]<='F')&&(s2[i]>='D'&&s2[i]<='F'&&flag==true)))
            cout << '1';
        else
        {
            cout << '0';
            flag = false;
        }
    }

    for(int i = 2;i <= 2;i++)
    {
        if(s1[i]=='D'&&s2[i]=='F'&&flag==true || s1[i]=='F'&&s2[i]=='D'&&flag==true)
            cout << '1';
        else if(s1[i]=='A'&&s2[i]=='B'&&flag==true || s1[i]=='B'&&s2[i]=='A'&&flag==true)
        {
            cout << '1';
        }
        else if(s1[i]=='B'&&s2[i]=='C'&&flag==true || s1[i]=='C'&&s2[i]=='B'&&flag==true)
        {
            cout << '1';
        }
        else
            cout << '0';
    }
    return 0;
}
