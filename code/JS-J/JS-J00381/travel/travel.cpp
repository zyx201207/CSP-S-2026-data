#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c[10],d[10];
    for(int i=1;i<=5;i++) cin>>c[i];
    for(int i=1;i<=5;i++) cin>>d[i];
    if(c[1]==d[1]&&c[2]==d[2]){
        cout<<1;
        if(c[3]==d[3]&&c[4]==d[4])
        {
            cout<<1;
            if((c[5]>='D'&&c[5]<='F')&&(d[5]>='D'&&d[5]<='F')) cout<<11;
            else if((c[5]>='A'&&c[5]<='C')&&(d[5]>='A'&&d[5]<='C'))
            {
                cout<<1;
                if((c[5]-d[5])>=-1&&(c[5]-d[5])<=1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
