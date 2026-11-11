#include<bits/stdc++.h>
using namespace std;
struct node{
    char c;
    long long sum;
}a[200005];
int n;
long long sum,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].sum>>a[i].c,sum+=a[i].sum;
    for(int i=1,j=n;sum>1;i=i){
        if(a[i].c==a[j].c)ans-=min(a[i].sum,a[j].sum);
        ans+=min(a[i].sum,a[j].sum);
        sum-=2*min(a[i].sum,a[j].sum);
        if(a[i].sum>a[j].sum)a[i].sum-=a[j].sum,j--;
        else a[j].sum-=a[i].sum,i++;
    }
    cout<<ans;
    return 0;
}
