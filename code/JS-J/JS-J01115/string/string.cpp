#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
struct node{
    int l;
    char c;
}a[N];
struct node2{
    int x,len;
};
int n;
long long sum1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
        sum1+=a[i].l;
    }
    long long sum=0;
    long long ans=0;
    node2 l={1,a[1].l},r={n,a[n].l};
    bool flag=0;
    for(int i=1;i<=n;i++){
        while(l.len>=0){
            if(sum==sum1/2){
                flag=1;
                break;
            }
            sum++;
            l.len--;
            r.len--;
            if(r.len<0){
                r.x--;
                r.len=a[r.x].l;
            }
            if(a[l.x].c!=a[r.x].c){
                ans++;
            }
        }
        if(flag){
            break;
        }
        l={i,a[i].l};
    }
    cout<<ans<<endl;
    return 0;
}
