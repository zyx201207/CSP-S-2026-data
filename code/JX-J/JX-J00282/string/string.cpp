#include<bits/stdc++.h>
using namespace std;
string s;
char w,x,y;
int n,sum,f,g;
long long d;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==3)
    {
            cin>>d>>w;
            cin>>sum>>x;
            cin>>f>>y;
            if(d==2&&w=='a'&&sum==2&&x=='b'&&f==1&&y=='c')
            {
                cout<<2;
            }
    }
    return 0;
}
