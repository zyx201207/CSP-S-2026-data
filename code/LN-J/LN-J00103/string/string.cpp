#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct hw{
    int a;
    char b;
}a[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].a>>a[i].b;
    }
    int b=0,c=a[0].a,d=n-1,e=a[n-1].a;
    while(1){
        if(b>=d){
            break;
        }
        if(a[b].b==a[d].b){
            if(c==e){
                b++,d--;
                c=a[b].a;
                e=a[d].a;
            }
            else if(c>e){
                c-=e;
                d--;
                e=a[d].a;
            }
            else{
                e-=c;
                b++;
                c=a[b].a;
            }
        }
        else{
            ans+=min(e,c);
            if(c==e){
                b++,d--;
                c=a[b].a;
                e=a[d].a;
            }
            else if(c>e){
                c-=e;
                d--;
                e=a[d].a;
            }
            else{
                e-=c;
                b++;
                c=a[b].a;
            }
        }
    }
    cout<<ans;
    return 0;
}
