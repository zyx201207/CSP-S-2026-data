#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n;
struct Node{
    long long num;
    char c;
}d[maxn];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>d[i].num>>d[i].c;
    }
    long long l=1,r=n;
    while(l<r){
        if(d[l].c!=d[r].c)ans+=1ll*min(d[l].num,d[r].num);
        if(d[l].num>d[r].num){
            d[l].num-=d[r].num;
            r--;
        }
        else if(d[l].num<d[r].num){
            d[r].num-=d[l].num;
            l++;
        }
        else{
            l++,r--;
        }
    }
    cout<<ans;
    return 0;
}
