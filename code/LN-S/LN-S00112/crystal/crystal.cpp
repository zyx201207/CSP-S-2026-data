#include<bits/stdc++.h>
using namespace std;
int a[10008];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x,sum=0;
        if(m!=0){
           m-=a[i];
           a[x]++;
        }
        else if(a[x]==a[i]){
            sum+=a[x];
        }

    }
    cout<<sum;
    return 0;
}
