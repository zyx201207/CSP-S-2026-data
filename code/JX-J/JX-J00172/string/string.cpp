#include<bits/stdc++.h>
using namespace std;
long long summ,tong[300],n,sum,ma,h;
struct stu{
   long long shu;
   char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
     cin>>a[i].shu>>a[i].c;
         summ+=a[i].shu;
         tong[int(a[i].c)]+=a[i].shu;
    }
    for(int i=1;i<n;i++){
        if(a[i].c!=a[i-1].c){
            sum++;
        }
    }
    if(sum==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<300;i++){
        ma=max(tong[i],ma);
    }
    if(n%2==0){
        for(int i=0;i<300;i++){
             h+=tong[i];
        }
        cout<<h-ma;
    }
    return 0;
}
