#include<bits/stdc++.h>
char a[10],b[10],c[10],d[10];
int m,n;
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]==c[0] and a[1]==c[1])
    {
        cout<<"1";
        if(b[0]==d[0] and b[1]==d[1])
        {
            cout<<"1";
                if(b[2]=='D' and d[2]!='F' or b[2]=='F' and d[2]!='D')
                {
                    cout<<"00";
                }
                else
                {

                    cout<<"1";
                    if(b[2]-'A'+d[2]-'A'==1 or b[2]-'A'+d[2]-'A'==3 or b[2]-'A'+d[2]-'A'==8)
                        cout<<"1";
                    else
                        cout<<"0";
                }
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
