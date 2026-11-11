#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
#define unsigned long long
#define PII pair<int,int>
const int N=5e5+10;
LL a[N];
int main(){
    IOS;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    LL num=0;
    LL ans=0;
    LL k=1;
    LL sum=1;
    for(LL i=1;i<=n;i++){
        if(i!=1) num+=(a[i]-a[i-1])*ans;
        ans++;
        while(num>m){
            ans--;
            num-=a[i]-a[k];
            k++;
        }
        sum=max(ans,sum);
    }
    cout<<sum;
    return 0;
}
