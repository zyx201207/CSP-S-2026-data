#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
long long tree[2000003],tag[2000003],a[500003];
vector<long long>b(500003);
long long read(){
    long long num=0;
    char c=getchar();
    while(c>='0' and c<='9'){
        num*=10;
        num+=(c-'0');
        c=getchar();
    }
    return num;
}
void push_up(int q,int l,int r){
    tree[q]=tree[q*2]+tree[q*2+1];
}
void push_down(int q,int l,int r){
    int mid=(r+l)/2;
    tree[q*2]+=(mid-l+1)*tag[q];
    tree[q*2+1]+=(r-mid)*tag[q];
    tag[q*2]+=tag[q];
    tag[q*2+1]+=tag[q];
    tag[q]=0;
}
void build(int q,int l,int r){
    if(l==r)tree[q]=a[l];
    else{
        int mid=(l+r)/2;
        build(q*2,l,mid);
        build(q*2+1,mid+1,r);
        push_up(q,l,r);
        tag[q]=0;
    }
}
void add(int q,int l,int r,int lx,int rx,long long num){
    if(lx<=l and r<=rx){
        tree[q]+=(r-l+1)*num;
        tag[q]+=num;
    }else{
        int mid=(r+l)/2;
        push_down(q,l,r);
        if(mid>=lx)add(2*q,l,mid,lx,rx,num);
        if(mid+1<=rx)add(2*q+1,mid+1,r,lx,rx,num);
        push_up(q,l,r);
    }
}
long long ques(int q,int l,int r,int lx,int rx){
    if(lx<=l and r<=rx)return tree[q];
    else{
        int mid=(r+l)/2;
        long long num=0;
        push_down(q,l,r);
        if(mid>=lx)num+=ques(2*q,l,mid,lx,rx);
        if(mid+1<=rx)num+=ques(2*q+1,mid+1,r,lx,rx);
        return num;
    }
}
void solve(int i){
    int l=1,r=i;
    while(l<r){
        int mid=(l+r)/2;
        if(ques(1,1,n,mid,i)<=m)r=mid;
        else l=mid+1;
    }ans=max(ans,i-l+1);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=0;i<n;i++)cin>>b[i];
    sort(b.begin(),b.begin()+n);
    for(int i=1;i<n;i++)a[i]=b[i]-b[i-1];
    a[n]=0;
    n--;
    build(1,1,n);
    for(int i=1;i<=n;i++){
        solve(i);
        add(1,1,n,1,i,a[i+1]);
    }
    cout<<ans+1;
    return 0;
}
