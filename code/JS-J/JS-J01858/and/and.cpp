#include<bits/stdc++.h>
using namespace std;
int n,m;
int get_num(long long x){
    int cnt=0;
    while(x){
        x&=(x-1);
        cnt++;
    }
    return cnt;
}
struct node{
    int num1=0;
    long long data;
}a[200005];
bool cmp(node a,node b){
    if(a.num1!=b.num1)return a.num1>b.num1;
    return a.data>b.data;
}
bool flag1=false,flag2=true;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    int x=__lg(n);
    if(pow(2,x)==n)flag1=true;
    for(int i=1;i<=n;i++){
        cin>>a[i].data;
        a[i].num1=get_num(a[i].data);
        if(a[i].data!=i-1)flag2=false;
    }
    if(flag1&&flag2){
        cout<<n-m;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    long long ans=a[1].data;
    for(int i=2;i<=m;i++){
        ans&=a[i].data;
    }
    cout<<ans;
    return 0;
}
