#include<bits/stdc++.h>
using namespace std;

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

int main()
{



    string s1,s2;
    int a,b;
    char c,d;
    cin>>s1>>a>>c>>s2>>b>>d;
    int ans=0;
    if(s1==s2)
    {
        ans=1;
        printf("%d",ans);
    }
    else
    {
        ans=0;
        printf("%d",ans);
    }
    if(a==b&&ans==1)
    {
        ans=1;
        printf("%d",ans);
    }
    else
    {
        ans=0;
        printf("%d",ans);
    }
    if(((c<='C'&&d<='C')||(c>'C'&&d>'C'))&&ans==1)
    {

        ans=1;
        printf("%d",ans);
    }
    else
    {

        ans=0;
        printf("%d",ans);
    }
    if((abs(c-d)==1||(c>'C'&&d>'C'))&&ans==1)
    {
        ans=1;
        printf("%d",ans);
    }
    else{
        ans=0;
        printf("%d",ans);
    }
    return 0;
}
