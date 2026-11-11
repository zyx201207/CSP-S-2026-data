#include<iostream>
using namespace std;
const int N=2e5+5;
struct node{
    int a;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i].a,&a[i].c);
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(a[l].a<a[r].a){
            if(a[l].c!=a[r].c) ans+=a[l].a;
            a[r].a-=a[l].a;
            l++;
        }
        else{
            if(a[l].c!=a[r].c) ans+=a[r].a;
            a[l].a-=a[r].a;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
