

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000];
bool f;
long long suma,sumtotal,mxcnt;
bool found(int x){
    for(int i=1;i<=n;i++){
        if(x==a[i]) return true;
    }
    return false;
}
long long judge(int x,int y,int z){
    int test=y/x;
    bool b=found(test);
    if(b) return x;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sumtotal=suma=m;
    for(int i=1;i<=n;i++){
        suma+=a[i];
        sumtotal+=suma;
        mxcnt=max(judge(i,suma,sumtotal),mxcnt);
    }
    cout<<mxcnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

