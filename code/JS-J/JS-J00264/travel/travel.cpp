#include<bits/stdc++.h>
using namespace std;
string R,X;
int r,x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>R>>x>>X;
    if(r==x)
    {
        char rr=R[0],rrr=R[1];
        char xx=X[0],xxx=X[1];
        if(rr==xx&&rrr==xxx)
        {
            if((R[2]=='A'&&(X[2]=='B'||X[2]=='C'))||(R[2]=='B'&&(X[2]=='A'||X[2]=='C'))||(R[2]=='C'&&(X[2]=='B'||X[2]=='A'))||(R[2]=='F'&&X[2]=='D')||(R[2]=='D'&&X[2]=='F'))
            {
                if((abs(R[2]-X[2])==1&&R[2]!='C'&&R[2]!='D'&&X[2]!='C'&&X[2]!='D')||(R[2]=='F'&&X[2]=='D')||(R[2]=='D'&&X[2]=='F'))cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
}
