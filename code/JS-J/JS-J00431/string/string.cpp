#include<bits/stdc++.h>
using namespace std;
long long n,asd,L,R,ans=0,p=0;
int l1,r1;
char c;
struct node{
    long long l,r;
    char q;
}a[300001];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>asd>>c;
    a[i].l=p+1,a[i].r=p+asd,a[i].q=c;
    p+=asd;
}
l1=1,r1=n;
while(l1<r1){
    if(a[l1].r-a[l1].l+1>a[r1].r-a[r1].l+1){
            if(a[l1].q==a[r1].q){
            ;
        }
        else {
            ans+=a[r1].r-a[r1].l+1;
        }
            a[l1].l+=(a[r1].r-a[r1].l+1);
    r1--;


    }
    else if(a[l1].r-a[l1].l+1==a[r1].r-a[r1].l+1){
        if(a[l1].q==a[r1].q);
        else ans+=a[l1].r-a[l1].l+1;
        l1++,r1--;
    }
    else{
        if(a[l1].q==a[r1].q){
            ;
        }
        else ans+=a[l1].r-a[l1].l+1;
        l1++,a[r1].r=p-a[l1-1].r;
    }
}
cout<<ans;
return 0;
}
