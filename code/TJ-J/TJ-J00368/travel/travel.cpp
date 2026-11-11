#include<bits/stdc++.h>
using namespace std;
int c[2],s2[255],s3[255];
char s[10]={'X','A','B','C','X','D','F','X'};
string R,X;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    s2['A']=1;
    s2['B']=2;
    s2['C']=3;
    s2['D']=5;
    s2['F']=6;//02 01A 02 01B
    s3['A']=1;
    s3['B']=1;
    s3['C']=1;
    s3['D']=2;
    s3['F']=2;
    cin>>c[0]>>R>>c[1]>>X;
    if(c[0]==c[1])
    {
        cout<<1;
        if(R[0]==X[0]&&R[1]==X[1])
        {
            cout<<1;
            if((s3[R[2]]==s3[X[2]]))
            {
                cout<<1;
                if((s[s2[R[2]]]==s[s2[X[2]]+1])||(s[s2[R[2]]]==s[s2[X[2]]-1]))
                {
                    cout<<1;
                }
                else
				{
                    cout<<"0";
                    return 0;
                }
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
