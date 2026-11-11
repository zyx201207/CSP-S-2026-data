#incude <bits/stdc++.h>
using namespace std;


main{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    while(q--){
        cin<<a<<c;
        int minn=h[a],maxn=h[a];
        for(int i=a+1;i<=c;i++){
            if(minn>h[i])minn=h[i];
            if(maxn<h[i])maxn=h[i];
            }
            cout<<m[i];
    return 0;
}

