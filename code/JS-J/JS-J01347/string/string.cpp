#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
    long long l;
    char c;
}a[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l;
        cin>>a[i].c;
    }
    long long L=1,R=n;
    while(L<R){
        if(a[L].c!=a[R].c){
            if(a[L].l>a[R].l){
                ans+=a[R].l;
                a[L].l-=a[R].l;
                R--;
            }else if(a[L].l<a[R].l){
                ans+=a[L].l;
                a[R].l-=a[L].l;
                L++;
            }else{
                ans+=a[L].l;
                L++;
                R--;
            }
        }else{
            if(a[L].l>a[R].l){
                a[L].l-=a[R].l;
                R--;

            }else if(a[L].l<a[R].l){
                a[R].l-=a[L].l;
                L++;
            }else{
                L++;
                R--;
            }
        }
    }
    cout<<ans;
    return 0;
}
