#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
    long long sum;
    char c;
};
node arr[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x;
        cin>>c;
        arr[i].sum=x;
        arr[i].c=c;
    }
    long long lt=1,rt=n,ans=0;
    while(lt<rt){
        long long mi=min(arr[lt].sum,arr[rt].sum);
        arr[lt].sum-=mi;
        arr[rt].sum-=mi;
        if(arr[lt].c!=arr[rt].c){
            ans+=mi;
        }
        if(arr[lt].sum==0){
            lt++;
        } if(arr[rt].sum==0){
            rt--;
        }
    }
    cout<<ans;
    return 0;

}

