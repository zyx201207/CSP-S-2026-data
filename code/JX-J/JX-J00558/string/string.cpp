#include<bits/stdc++.h>
using namespace std;
int n,sum=0,ma=-1,f=1;
struct s{
   int m;
   char z;
}p[100001];
bool cmp(s a,s b){
     if(a.z==b.z){
        a.m=b.m+a.m;
        b.m=0;
        return a.m>b.m;
     }
     else{
        return a.m>b.m;
     }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].m>>p[i].z;
        sum+=p[i].m;
    }
    for(int i=1;i<n;i++){
        if(p[i].z!=p[i+1].z){
            f=0;
        }
    }
    if(f==1){
        cout<<0;
        return 0;
    }
    sort(p+1,p+sum+1,cmp);
    ma=p[1].m;
    for(int i=2;i<=n;i++){
        if(p[i].m==ma){
            cout<<ma;
            return 0;
        }
    }

    if(sum%2==1){
        cout<<sum-ma-1;
    }
    else{
        cout<<sum-(ma*2);
    }
    return 0;
}
