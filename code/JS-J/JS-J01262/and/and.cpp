#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        int x=0;
        for(int i=1;i<=n;i++){
            x=x&a[i];
        }
        cout<<x;
        return 0;
    }
    if(m==2){
        int max=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]&a[j]>=max && j!=i){
                    max=a[i]&a[j];
                }
            }
        }
        cout<<max;
    }
    return 0;
}
