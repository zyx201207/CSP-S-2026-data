#include <iostream>
#include <algorithm>
using namespace std;

const int N=2e5+5;
int a[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int maxx;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        maxx=max(a[i],maxx);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;++i){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
        return 0;
    }
    if(m&1==0){
        int t=0,ans=0;
        for(int i=1;i<=n;++i){
            for(int j=i+m-1;j<=n;++j){
                t=a[i]&a[j];
                ans=max(t,ans);
            }
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    cout<<a[m];
    return 0;
}
