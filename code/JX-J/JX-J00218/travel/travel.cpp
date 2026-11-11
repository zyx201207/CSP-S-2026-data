#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[5]={0,0,0,0,0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='D')s1[2]='E';
    if(s2[2]=='D')s2[2]='E';
    if(c1==c2)
    {
        ans[1]=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            ans[2]=1;
            if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='E'&&s1[2]<='F'&&s2[2]>='E'&&s2[2]<='F'))
            {
                ans[3]=1;
                if(abs(s1[2]-s2[2])<=1)
                ans[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++)cout<<ans[i];
    return 0;
}
