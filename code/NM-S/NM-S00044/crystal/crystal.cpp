#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int mm=5e5+100;
long long a[mm],b[mm];
bool check(int len){
    long long sum=0;
    for(int i=1;i<len;i++){
        sum=sum+(len-i)*b[len-i];
    }
    if(sum<=m)return true;
    for(int i=0;i<n-len;i++){
        sum=sum-(a[len+i-1]-a[i])+(len-1)*b[i+len];
        if(sum<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(int i=1;i<n;i++)b[i]=a[i]-a[i-1];
//尝试二分
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
  //好像可以，正在进行，15；41
    cout<<l;
    return 0;
}
//我去，好吓人，调试时发现freopen的文件是apple
//完蛋测试点结果前三正确，最后差一
//没问题了，封装 ，预计得70分，16：05加油
