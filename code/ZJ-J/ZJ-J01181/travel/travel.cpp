#include<bits/stdc++.h>
using namespace std;
int Side(char s)
{
    if(s>='A'&&s<='C')
    {
        return 1;
    }
    return 2;
}
int Near(string s1,string s2)
{
    int num1=s1[0]*10+s1[1],num2=s2[0]*10+s1[1];
    int num3=s1[2]-'A',num4=s2[2]-'A';
    if(s1[2]==s2[2]&&abs(num1-num2)==1)
    {
        return 1;
    }
    if(num1==num2&&abs(num3-num4)==1)
    {
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ans1=0,ans2=0,ans3=0,ans4=0;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int num1=s1[0]*10+s1[1],num2=s2[0]*10+s1[1];
    int side1=Side(s1[2]),side2=Side(s2[2]);
    if(c1==c2)
    {
        ans1=1;
        if(num1==num2)
        {
            ans2=1;
            if(side1==side2)
            {
                ans3=1;
            }
        }
        ans4=Near(s1,s2);
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
