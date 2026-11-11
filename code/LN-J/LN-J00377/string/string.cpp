#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,zhi;
};
node a[200005],b[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long p=1;
    for(int i=1;i<=n;i++){
        int c;
        char z;
        cin>>c>>z;
        a[i].l=p;
        a[i].r=p+c-1;
        p+=c;
        a[i].zhi=int(z);
    }
    p-=1;
    int x=1,y=n,l1=1,r1=p;
    long long ans=0;
    while(l1<=r1){
        if(a[x].r<p-a[y].l+1){
            if(a[x].zhi!=a[y].zhi){
                ans+=a[x].r-l1+1;
            }
            l1=a[x].r+1;
            r1=p-a[x].r+1;
            x++;
        }
        else if(a[x].r==p-a[y].l+1){
            if(a[x].zhi!=a[y].zhi){
                ans+=a[x].r-l1+1;
            }
            l1=a[x+1].l;
            r1=a[y-1].r;
            x++;
            y--;
        }
        else{
            if(a[x].zhi!=a[y].zhi){
                ans+=(p-a[y].l+1)-l1+1;
            }
            l1=(p-a[y].l+1)+1;
            r1=a[y-1].r;
            y--;
        }
    }
    cout<<ans;
}
