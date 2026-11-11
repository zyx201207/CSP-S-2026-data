#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
    int ai;
    char ci;
}a[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ai>>a[i].ci;
    }
    int l=1,r=n,sum=0;
    while(l<r){
        int t=abs(a[l].ai-a[r].ai);
        if(a[l].ci!=a[r].ci)
            sum+=min(a[l].ai,a[r].ai);
        if(a[l].ai<a[r].ai){
            l++;
            a[r].ai=t;
        }
        else{
            r--;
            a[l].ai=t;
        }
    }
    cout<<sum<<'\n';
    return 0;
}
