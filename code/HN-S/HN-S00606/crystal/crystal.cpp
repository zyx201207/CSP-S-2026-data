#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
long long a[maxn];
int main(){
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    while(m>0){
        for(int i=1;i<=n;i++){
            if(a[i]<a[i+1]){
                m--;
                a[i]++;
                break;
            }
        }
    }
    int k=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[1]){
            break;
        }
        k++;
    }
    cout<<k;
    return 0;
}
