#include<bits/stdc++.h>
using namespace std;
struct node{
    int b;
    char c;
}a[200050];
int n,l,r;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].b);
        a[i].c=getchar();
        a[i].c=getchar();
    }
    l=1;
    r=n;
    while(l<r){
        if(a[l].b==a[r].b){
            if(a[l].c!=a[r].c){
                ans+=a[l].b;
            }
            l++;
            r--;
        }
        if(a[l].b<a[r].b){
            if(a[l].c!=a[r].c){
                ans+=a[l].b;
            }
            a[r].b-=a[l].b;
            l++;
        }
        if(a[l].b>a[r].b){
            if(a[l].c!=a[r].c){
                ans+=a[r].b;
            }
            a[l].b-=a[r].b;
            r--;
        }
    }
    printf("%lld",ans);
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
*/
