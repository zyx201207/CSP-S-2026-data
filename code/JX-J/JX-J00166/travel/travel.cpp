#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int ph=0;
    int zwr=0;
    int zwx=0;
    int ans=0;
    bool xl=false;
    cin>>c1>>s1>>c2>>s2;
    int zmr=s1[2]+0;
    int zmx=s2[2]+0;
    if(zmr-zmx==1||zmr-zmx==-1)
    {
        xl=true;
    }
    for(int i=0; i<=1; i++)
    {
        if(s1[i]==s2[i])ph++;
    }
    if(zmr-65<=2)
    {
        zwr=1;
    }
    if(zmx-65<=2)
    {
        zwx=1;
    }
    if(c1==c2)
    {
        ans++;
        if(ph==2)
        {
            ans++;
            if(zwr==zwx)
            {
                ans++;
                if(xl)
                {
                    ans++;
                }
            }

        }
    }




    if(ans==0)
    {
        cout<<"0000";
    }
    if(ans==1)
    {
        cout<<"1000";
    }
    if(ans==2)
    {
        cout<<"1100";
    }
    if(ans==3)
    {
        cout<<"1110";
    }
    if(ans==4)
    {
        cout<<"1111";
    }
    return 0;
}
