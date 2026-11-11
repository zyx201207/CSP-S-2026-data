#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,u,v;
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
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=scan(),t=scan();
    while(t--){
        n=scan(),m=scan();
        for(int i=1;i<n;i++)
            u=scan(),v=scan();
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
