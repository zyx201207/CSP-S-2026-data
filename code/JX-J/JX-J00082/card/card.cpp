#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,int>mp;
int a[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    a[n+1]=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[i]++;
    }
    bool f=0;
    for(int i=2;i<=n;i++){
        if(a[i-1]>a[i]){
            f=1;
            break;
        }
    }
    if(f==0){
        for(int i=1;i<=n;i++){
            if(a[i+1]>a[i]){
                cout<<i<<" ";
            }
        }
        return 0;
    }
    return 0;
}
