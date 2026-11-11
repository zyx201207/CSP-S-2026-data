#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int s=a[i];
        for(int j=i+1;j<=i+m;j++){
            s=s&a[j];
        }
        cout<<"s:"<<s<<endl;
        maxn=max(s,maxn);
    }
    cout<<maxn;

    return 0;
}
