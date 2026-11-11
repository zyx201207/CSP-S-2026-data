#include<bits/stdc++.h>
using namespace std;
char q[2000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    long long w=1;
    char c,op=' ';
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%c%c",&a,&op,&c);
        while(a--){
            q[w]=c;
            w++;
        }
    }
    w-=1;
    long long m=w/2,s=0;
    for(long long i=1;i<=m;i++){
        if(q[i]!=q[w+1-i]) s++;
    }
    printf("%lld",s);
    return 0;
}
