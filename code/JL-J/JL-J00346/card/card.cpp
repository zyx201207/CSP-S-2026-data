#incude <bits/stdc++.h>
using namespace std;


main{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    while(q--){
        cin<<a<<b;
        int minn=h[a],maxn=h[a];
        for(int i=a+1;i<=b;i++){
            if(minn>h[i])minn=h[i];
            if(maxn<h[i])maxn=h[i];
            }
            cout<<m[i];
    }
    return 0;
}

