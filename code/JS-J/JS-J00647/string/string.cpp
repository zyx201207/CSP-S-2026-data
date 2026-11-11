#include<bits/stdc++.h>
using namespace std;
long long n,p,sum;
struct node{
    long long b;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].b>>a[i].c;
    }
    for(int i=1;i<=n/2;i++){
        if(a[i].c==a[n+1-i].c){
            if(abs(i-(n+1-i))<=1) break;
            else sum+=abs(a[i].b-a[n+1-i].b);
        }
        else{
            sum+=abs(a[i].b-a[n+1-i].b)+min(a[i].b,a[n+1-i].b);
        }
    }
    cout<<sum;
    return 0;
}
