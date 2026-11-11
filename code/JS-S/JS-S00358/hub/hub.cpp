#include<bits/stdc++.h>
using namespace std;
long long n,m,A[500005];
int qread(){
    int x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) {
        if(c=='-') f=-1;
    }
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
/*
int erfeng(long long x){

}
 */

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    n = qread();m = qread();
    for(int i=1;i<=n;i++)
        A[i]=qread();
    sort(A+1,A+n+1);

    return 0;
}
