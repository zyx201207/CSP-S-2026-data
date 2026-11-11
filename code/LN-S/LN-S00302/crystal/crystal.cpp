#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e5+5;
long long a[MAXN];
unsigned long long b[MAXN];
int n;
long long m;
queue<int> q;
long long inque=0;
int ans=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //cout<<"cin complete"<<endl;
    sort(a,a+n);
    b[0]=0;
    for(int i=1;i<n;i++){
        b[i]=a[i]-a[i-1];
    }
    for(int i=0;i<n;i++){
        inque+=b[i]*q.size();
        q.push(i);
        while(inque>m){
            inque-=a[q.back()]-a[q.front()];
            q.pop();
        }
        ans=max(ans,(int)q.size());
    }
    cout<<ans<<'\n';
    return 0;
}
