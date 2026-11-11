#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int cnt[N];
int t[M];
int temp[M];
stack<long long> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","W",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            t[a[j]]++;
        }
        for(int j=1;j<=m;j++){
            if(t[j]>0){
                temp[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<temp[i]<<" ";
    }
    return 0;
}
