#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,x,ans=2147483647,pos=1,ii=1;
struct number{
    long long h=0,num=0,nm=0;
}a[200200];
void init(long long x,long long i){
    long long maxnum=0,nnum=0;
    a[i].nm=x;
    while(x>1){
        if (x%2==1) nnum++;
        x/=2;
        maxnum++;
    }
    a[i].h=maxnum,a[i].num=nnum;
}
bool cmp(number a,number b){
    if (a.num==b.num) return a.h>b.h;
    return a.num>b.num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (long long i=1;i<=n;i++){
        cin>>x;
        init(x,i);
    }
    sort(a+1,a+1+n,cmp);
    while(ii<=m){
        if (pos>n){
            cout<<0;
            return 0;
        }
        if ((ans%(a[pos].nm))!=0){
            ans=ans&a[pos].nm,ii++;
        }
        else{
            pos++;
        }
    }
    cout<<ans;
    return 0;
}
