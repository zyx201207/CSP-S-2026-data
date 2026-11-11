#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
int a[500010];
int pre[500010];
int n,m;
int sum(int l,int r){
    return pre[r]-pre[l-1];
}
bool check(int mid){
    for(int i=1;i+mid-1<=n;i++){
        int l=i,r=i+mid-1;
        if(a[r]*mid-sum(l,r)<=m){
            //cout<<"check:"<<mid<<"true"<<l<<' '<<r<<endl;
            return true;
        }
    }
    //cout<<"check:"<<mid<<"false"<<endl;
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n+1;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    write(l-1);
    putchar('\n');
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

binary search the ans
for each mid, check() use O(n) scan the array
when lenth==mid, caculate the value
to transform every crystal in to the largest one
total time complexity: O(nlogn)

why forget to init prefix and debuged for 20min bruh
AHHHHHHHHH

14:55 A pass
*/