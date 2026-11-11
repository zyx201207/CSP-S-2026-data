#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
        if( (b[1]-'0')  + (b[0]-'0') *10== (d[1]-'0') + (d[0]-'0')*10 )
        {
            cout<<1;
            if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')
            {
                cout<<1;
                if(b[2]-d[2]==1||d[2]-b[2]==1||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')
                    cout<<1;
                else
                    cout<<0;
            }
            else
                cout<<0<<0;
        }
        else
            cout<<0<<0<<0;
    }
    else
    {
        cout<<0<<0<<0<<0;
    }
	return 0;
}
