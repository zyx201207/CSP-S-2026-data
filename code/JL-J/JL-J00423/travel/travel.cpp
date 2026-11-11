#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int k=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c)
    cout<<"0000";
    if(a==c)
    {
        for(int i=0;i<2;i++)
        {
            if(b[i]!=d[i])
            {
                cout<<"1000";
                k=0;
                return 0;
            }
        }
        if(k==1)
        {
            if(b[2]-'A'<=2&&d[2]-'A'>2||b[2]-'A'>2&&d[2]-'A'<=2)
            {
                cout<<"1100";
                return 0;
            }
            else
            {
                if(b[2]-'A'>2&&d[2]-'A'>2)
                {
                    cout<<"1111";
                    return 0;
                }
                if(abs(b[2]-d[2])==1)
                {
                    cout<<"1111";
                    return 0;
                }
                if(abs(b[2]-d[2])==2)
                {
                    cout<<"1110";
                    return 0;
                }
            }
        }
    }
    return 0;
}
