#include <bits/stdc++.h>

using namespace std;
int r1;
int x1;
bool pd=false;
char jl[3]={'A','B','C'};
string r2;
string x2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1;
    cin>>r2;
    cin>>x1;
    cin>>x2;
    if(r1==x1)
    {
        cout<<1;
        if(r2[0]==x2[0]&&r2[1]==x2[1])
        {
            cout<<1;
            if((r2[2]=='D'&&x2[2]=='F')||(r2[2]=='F'&&x2[2]=='D'))
            {
                cout<<11<<endl;
                return 0;
            }
            if((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'))
            {
                cout<<1;
                if(r2[2]-x2[2]==1||r2[2]-x2[2]==-1)
                {
                    cout<<1;
                    return 0;
                }
                cout<<0;
                return 0;
            }
            cout<<"00"<<endl;
        }
        else
        {
            cout<<"000"<<endl;
        }
    }
    else
    {
        cout<<"0000"<<endl;
    }
    return 0;
}
