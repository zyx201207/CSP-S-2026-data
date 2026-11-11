#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n;
int x;
char y;
int a[maxn];
char c[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    //special
    bool flag=0;
    for(int i=1;i<n;i++){
        if(c[i]!=c[i+1]){
            flag=1;
        }
    }
    if(flag==0){
        cout<<0;
        return 0;
    }

    int l=1,r=n;
    long long ans=0;

    while(l<r){
        if(c[l]==c[r]){
            int t=abs(a[l]-a[r]);
            ans+=t;
        }else{
            int t=max(a[l],a[r]);
            ans+=t;
        }
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
