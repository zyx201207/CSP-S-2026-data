#include <bits/stdc++.h>
using namespace std;
struct node{
    long long inner;
    long long distance;
};
node a[500002];
bool cmp(node a,node b){
    return a.distance<b.distance;
}
long long n,m;
long long ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].inner;
        ans+=a[i].inner;
    }
    ans/=n;
    for(int i=0;i<n;i++){
       a[i].distance=abs(a[i].inner-ans);
    }
    sort(a,a+n,cmp);
    ans=a[0].inner;
    for(int i=0;i<n;i++){
       a[i].distance=abs(a[i].inner-ans);
    }
    sort(a,a+n,cmp);
    int i=1;
    while(m>0){
        m-=a[i].distance;
        if(m>=0)i++;
    }
    cout<<i;
    return 0;
}

