#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long head=1,tail=n;
    while(head<tail){
        long long cnt=min(a[head],a[tail]);
        a[head]-=cnt;
        a[tail]-=cnt;
        if(b[head]!=b[tail]) ans+=cnt;
        if(a[head]==0) head++;
        if(a[tail]==0) tail--;
    }
    cout<<ans;
}
