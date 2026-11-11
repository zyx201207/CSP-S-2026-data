#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,s,d,f;
    char c1[3];
    char s1[4];
    char c2[3];
    char s2[4];
    char cs[5]="0";
    char er[5]="0";

    cin>>c1>>s1>>c2>>s2;
    if(c1[1]==c2[1] && c1[0]==c2[0] && c1[2]==c2[2] )
    {
        er[0]=1;
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            er[1]=1;
            if(s1[2]==s2[2]+1 )
            {
                if(s1[2]!='D')
                {
                    er[2]=1;
                }
            }

            if(s1[2]==s2[2]-1)
            {
                if(s1[2]!='C')
                {
                    er[2]=1;
                }
            }
        }
    }
    if(er[0]==er[1] && er[1]==er[2] && er[2]==er[3] && er[2]==1)
        er[3]=1;
    for(int p=0;p<4;p++)
        cout<<er[p];

    return 0;
}



