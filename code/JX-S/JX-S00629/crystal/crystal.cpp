#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cntlen=1,c[500005],ans=1;
queue<long long>q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        c[i]=a[i+1]-a[i];
    }
    q.push(a[1]);
    for(int i=1;i<n;i++){
        m-=(cntlen*c[i]);
        cntlen++;
        q.push(a[i+1]);
        while(!q.empty()&&m<0){
            m+=a[i+1]-q.front();
            q.pop();
            cntlen--;
        }
        ans=max(ans,cntlen);
    }
    cout<<ans;
    return 0;
}

