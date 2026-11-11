#include <bits/stdc++.h>
using namespace std;
boor pd(a,b,c,d)
{
    if(c1!="1"&&c1!="16"&&c2!="1"&&c2!="16")return c1 == c2;
    return s1[0]+s1[1] == s2[0]+s2[1];
    if((s1[2] == "c" && s2[2] == "D")||(s1[2] == "D" && s2[2] == "C"))
        return 0;
    else
    {
        return 1;
    }
    return 1;
    if((s1[2]=="A"&&s2[2]=="B")||(s1[2]=="B"&&s2[2]=="A"))return 1;
    else if(s1[2]=="B"&&s2[2]=="C")||(s1[2]=="C"&&s2[2]=="B"))return 1;
    else if(s1[2]=="D"&&s2[2]=="F")||(s1[2]=="F"&&s2[2]=="D"))return 1;
    else
    {
        return 0;
    }

}
int main()
{
    freopen("trawel.in","r",stdin);
    freopen("trawel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    pd(c1,s1,c2,s2);
    return 0;
}
