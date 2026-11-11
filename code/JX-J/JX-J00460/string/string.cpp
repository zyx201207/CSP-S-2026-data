#include<bits/stdc++.h>
using namespace std;
int n;
long long zong=0ll;
struct nod{
    long long x;
    char s;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].s;
        zong+=a[i].x;
    }
    long long cnt=0,j=n,i=1;
    while(i!=j){
        if(a[i].s!=a[j].s){
            if(a[i].x>=a[j].x){
                cnt+=a[j].x;
                a[i].x-=a[j].x;
                j--;
            }
            else{
                cnt+=a[i].x;
                a[j].x-=a[i].x;
                i++;
            }
        }else{
            if(a[i].x>=a[j].x){
                //cnt+=a[j].x;
                a[i].x-=a[j].x;
                j--;
            }
            else{
                //cnt+=a[i].x;
                a[j].x-=a[i].x;
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
