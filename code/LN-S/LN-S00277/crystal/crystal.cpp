#include<bits/stdc++.h>
using namespace std;
const int N=5000005;
long long a[N];
//1
long long sum=0;
long long ans=0;
long long aa=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long num=(sum+n-1)/n;
    for(int i=1;i<=n;i++){
        if(a[i]<=num){
            ans+=num-a[i];
            aa++;
            if(ans>=m){
                break;
            }
        }
    }
        if(ans>m){
            aa-=1;
        }
    cout<<aa;
    return 0;
}
