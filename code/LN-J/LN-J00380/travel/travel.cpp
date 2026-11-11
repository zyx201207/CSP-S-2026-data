#include<bits/stdc++.h>
using namespace std;
char a[5][5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    cin>>s1>>s2>>c1>>c2;
cin>>a[1][1]>>a[1][2]>>a[2][1]>>a[2][2]>>a[2][3]>>a[3][1]>>a[3][2]>>a[4][2]>>a[4][2]>>a[4][3];
if(a[1][1]==a[3][1]&&a[1][2]==a[3][2])
{
    cout<<1;
    flag1=1;
}
else
{
    cout<<0;
}
if(a[2][1]==a[4][1]&&a[2][2]==a[4][2]&&flag1)
{
 cout<<1;
 flag2=1;
}
else
{
    cout<<0;
}
if((a[2][3]="D"&&a[4][3]="F")||(a[2][3]="F"&&a[4][3]="D")||(a[2][3]="A"&&a[4][3]="B")||(a[2][3]="B"&&a[4][3]="A")||(a[2][3]="B"&&a[4][3]="C")(a[2][3]="C"&&a[4][3]="B"))
{
    if(flag2)
    {
        flag3=1;
        cout<<1;
    }
    if(flag3)
    {
    cout<<0;
    }
}
cout<<s1<<s2<<c1<<c2;
return 0;
}
