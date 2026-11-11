#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long num;
    char x;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int m=1;
    long long ans=0;
    char x;
    for(int i=1;i<=n;i++){
        cin>>a[m].num>>a[m].x;
        if(x==a[m].x)a[m-1].num+=a[m].num;
        else x=a[m++].x;
    }
    m--;
    int l=1,r=m;
    while(l<r){
        if(a[l].x==a[r].x){
            if(a[l].num==a[r].num)l++,r--;
            else if(a[l].num<a[r].num)a[r].num-=a[l++].num;
                else a[l].num-=a[r--].num;
        }
        else{
            if(a[l].num==a[r].num)ans+=a[l].num,l++,r--;
            else if(a[l].num<a[r].num)ans+=a[l].num,a[r].num-=a[l++].num;
                else ans+=a[r].num,a[l].num-=a[r--].num;
        }
    }
    cout<<ans;
    return 0;
}
