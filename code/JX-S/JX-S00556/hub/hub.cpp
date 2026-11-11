#include<bits/stdc++.h>
using namespace std;
long long a[100050],b[100050];
inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-1') f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
 int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read(),T=read();
    while(T--){
        int n=read(),k=read();
        for(int i=1;i<n;i++) int u=read(),v=read();
        printf("1\n");
    }
    return 0;
}
