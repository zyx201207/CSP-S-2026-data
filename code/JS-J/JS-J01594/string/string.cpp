#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct node{
    int num;
    char ch;
}a[N];
int n;
signed main() {
    freopen("string5.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int len=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i].num>>a[i].ch;
        len+=a[i].num;
    }
    int sum=0,tot=0;
    while(sum<=len/2) {
        sum+=a[++tot].num;
    }
    if(sum>len/2) sum-=a[tot].num;
    int ans=0,p=1,s=0;
    for(int i=n+1;i>=tot+1;i--) a[i]=a[i-1];
    if(len%2==0) {
        int size1=len/2-sum;
        a[tot+1].num=a[tot].num-size1;
        a[tot].ch=a[tot].ch;
        a[tot].num=size1;
    }
    else {
        int size1=len/2-sum;
        a[tot+1].num=a[tot].num-size1-1;
        a[tot].ch=a[tot].ch;
        a[tot].num=size1;
    }
    reverse(a+1+tot,a+1+n);
    for(int i=tot+1;i<=(tot+n+2)/2;i++) {
        swap(a[i],a[n+tot+2-i]);
    }
    // for(int i=1;i<=tot;i++) {
    //     for(int j=1;j<=a[i].num;j++) cout<<a[i].ch;
    // }
    for(int i=tot+1;i<=n+1;i++) {
        if(a[i].ch==a[p].ch) {
            if(a[i].num>a[p].num) {
                a[i].num-=a[p].num;
                p++;   
                i--;
            }
            else if(a[i].num<a[p].num){
                a[p].num-=a[i].num;
            }
            else p++;
        }
        else {
            if(a[i].num>a[p].num) {
                ans+=a[p].num;
                a[i].num-=a[p].num;
                p++;
                i--;
            }
            else if(a[i].num<a[p].num){
                ans+=a[i].num;
                a[p].num-=a[i].num;
            }
            else {
                ans+=a[p].num;
                p++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
3 a
1 b 
1 c
aaabb b bbccc
aaabb b acabb
*/