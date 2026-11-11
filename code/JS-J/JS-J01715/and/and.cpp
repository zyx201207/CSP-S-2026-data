#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[200005];
bool check(int mid){
    int ret1=0,ret2=0,ret3=0,p;
    p=(1<<31)-1;
    for(int i=1;i<=n;i++){
        if((p&a[i])>=mid)ret1++,p&=a[i];
    }
    p=(1<<31)-1;
    for(int i=1;i<=n;i++){
        if((p&a[n+1-i])>=mid)ret2++,p&=a[n+1-i];
    }
    for(int i=1;i<=n;i++){
        if((a[i]&mid)==a[i]-mid)ret3++;
    }
    return (ret1>=m)||(ret2>=m)||(ret3>=m);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=29;i>=0;i--){
        if(check(t+(1<<i)))t+=(1<<i);
    }
    printf("%d\n",t);
    return 0;
}
