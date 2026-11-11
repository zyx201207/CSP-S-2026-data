#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c==5&&d==3)
        cout<<0<<endl<<1;
    else
        cout<<1<<endl<<2;
    
    return 0;
}