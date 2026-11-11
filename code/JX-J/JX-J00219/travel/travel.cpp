#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    char s1[4]={0},s2[4]={0};
    cin>>c1;
    for(int i=1;i<=3;i++)
    {
        cin>>s1[i];
    }
    cin>>c2;
    for(int i=1;i<=3;i++)
    {
        cin>>s2[i];
    }
    int a[5]={0};
    if(c1==c2)
    {
        a[1]=1;
    }
    if(a[1]==1&&s1[1]==s2[1]&&s1[2]==s2[2])
    {
        a[2]=1;
    }
    if((a[1]==1&&'A'<=s1[3]&&'C'>=s1[3]&&'A'<=s2[3]&&'C'>=s2[3])||(a[1]==1&&'D'<=s1[3]&&'E'>=s1[3]&&'D'<=s2[3]&&'E'>=s2[3]))
    {
        a[3]=1;
    }
    if(a[1]==1&&a[2]==1&&a[3]==1)
    {
        if((s1[3]+=1)==s2[3])
        {
            a[4]=1;
        }
        if((s1[3]-=1)==s2[3])
        {
            a[4]=1;
        }
    }
    for(int i=1;i<=4;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
