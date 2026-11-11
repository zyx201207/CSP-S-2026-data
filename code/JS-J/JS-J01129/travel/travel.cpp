#include<bits/stdc++.h>

using namespace std;

string s1,s2,c1,c2;
int l,r;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        printf("0000");
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        printf("1000");
        return 0;
    }
    if(s1[2]>='A'&&s1[2]<='C')
        l++;
    else
        r++;
    if(s2[2]>='A'&&s2[2]<='C')
        l++;
    else
        r++;
    if(l==1&&r==1)
    {
        printf("1100");
        return 0;
    }
    char a=s1[2],b=s2[2];
    if(a>b)
        swap(a,b);
    if(b-a==1||a=='D'&&b=='F')
    {
        printf("1111");
        return 0;
    }
    printf("1110");
    return 0;
}
