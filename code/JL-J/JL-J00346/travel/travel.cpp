#incude <bits/stdc++.h>
using namespace std;


main{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    while(q--){
        cin<<a<<b<<c<<d:
        int minn=h[a],maxn=h[a];
        for(int i=a+1;i<=b;i++){
            if(minn>h[i])minn=h[i];
            if(maxn<h[i])maxn=h[i];
            }
            cout<<maxn-minn;
    return 0;
}

