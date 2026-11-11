#include<bits/stdc++.h>
using namespace std;//大数会爆掉
const int MAXN=2*1e5+10;
int com[MAXN];
void check(int n,int m,int A[],int start){
    if(m==1){
        for(int i=start;i<=n;i++)
            com[i]=A[i];
    }
    for(int i=start;i<=n;i++){
        check(n,m-1,A,i);
        com[i]&=A[i];
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a[MAXN],m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    check(n,m,a,1);
    sort(com,com+n);
    cout<<*(com+n);
     return 0;
}
