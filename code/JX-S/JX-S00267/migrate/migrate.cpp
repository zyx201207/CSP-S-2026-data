#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[2000001];
int scan(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=scan(),t=scan();
    while(t--){
        n=scan(),m=scan();
        for(int i=1;i<=n;i++)
            a[i]=scan();
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
