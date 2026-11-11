#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>s1>>c1>>s2>>c2;
    int ans1,ans2,ans3,ans4;
    //ans1:samecar
    if(s1==s2)
    {
        ans1=1;
    }
    else if(s1!=s2)
    {
        ans1=0;
    }
    //ans2:sameline
    if(c1[0]==c2[0]&&c1[1]==c2[1]&&ans1)
    {
        ans2=1;
    }
    else
    {
        ans2=0;
    }
    //ans3:samesideandsameline
    bool sameside;
    sameside=((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'))||((c1[2]=='D'||c1[2]=='F')&&(c2[2]=='D'||c2[2]=='F'));
    if(ans2==1&&sameside==1&&ans1)
    {
        ans3=1;
    }
    else
    {
        ans3=0;
    }
    //ans4:beside
    bool beside,df,abc;
    df=((c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D'));
    abc=(abs(c1[2]-c2[2])==1)&&sameside==1;
    beside=(df==1&&abc==0)||(df==0&&abc==1);
    if(beside&&ans3&&ans1)
    {
        ans4=1;
    }
    else
    {
        ans4=0;
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4;
    return 0;
}
