#include<bits/stdc++.h>
using namespace std;
int n;
struct z{
    long long f;
    char s;
}a[200005];
int have[27],maxh=-999999;
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].f;
        cin>>a[i].s;
        int l=int(a[i].s)-97;
        have[l]+=a[i].f;
    }
    int j=0;
    for(int i=0;i<=n;i++){
        if(have[i]!=0){
            j++;
        }
    }
    if(j==0){
        cout<<0;
        return 0;
    }
    return 0;
}
