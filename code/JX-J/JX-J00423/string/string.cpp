#include<bits/stdc++.h>
using namespace std;
struct node{
    char v;//val
    int l;//len
}a[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].v;
    }
    int l=1,r=n;
    while(l<=r){
        if(a[l].v!=a[r].v){
            if(a[l].l>a[r].l){
                ans+=a[r].l;
                a[l].l-=a[r].l;
                r--;
            }else if(a[l].l<a[r].l){
                ans+=a[l].l;
                a[r].l-=a[l].l;
                l++;
            }else{
                ans+=a[l].l;
                l++;
                r--;
            }
        }else{
            if(a[l].l>a[r].l){
                a[l].l-=a[r].l;
                r--;
            }else if(a[l].l<a[r].l){
                a[r].l-=a[l].l;
                l++;
            }else{
                l++;
                r--;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
