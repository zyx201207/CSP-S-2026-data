#include <bits/stdc++.h>
#define st string
#define forr(a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin >> a;
    st b , d;
    int c;
    forr(0,a,1)
    {
        cin>>c>>b;
        forr(0 , c , 1)
        {
            d+=b;
        }
    }
    int e=0,f=d.size()-1,badchar=0;
    forr(0,d.size()/2,1){
        if(d[e]!=d[f]){
            badchar++;
        }
        //cout<<e<<f;
        e++,f--;
    }
    cout<<badchar;
    return 0;
}
