#include<bits/stdc++.h>
using namespace std;
long long n,m,maxa;
struct node{
    long long num,gh;
}k[200005];
int ge(long long k){
    long long sum=0;
    while(k>0){
        int y=k%2;
        k/=2;
        if(y==1){
            sum++;
        }
    }
    return sum;
}
bool f(node x,node y){
    return x.num>y.num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>k[i].num;
        int u=k[i].num;
        k[i].gh=ge(u);
    }
    sort(k+1,k+n+1,f);
    int ogt=k[1].num;
    for(int i = 1;i<=m;i++){
        ogt=ogt&k[i].num;
    }
    cout<<ogt;
    return 0;
}
