#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
    long long l;
    char x;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].x;
    long long l=a[1].l,r=a[n].l;
    for(int i=1,j=n;i<=j;){
        if(a[i].x!=a[j].x)
            ans+=min(l,r);
        if(l==r){
            i++;
            j--;
            l=a[i].l;
            r=a[j].l;
        }else if(l>r){
            l-=r;
            j--;
            r=a[j].l;
        }else{
            r-=l;
            i++;
            l=a[i].l;
        }
    }
    cout<<ans;
    return 0;
}
