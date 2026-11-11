#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int a[10000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]>=a[i]){
                swap(a[j],a[i]);
            }
        }
    }
    for(int i=1;i<n;i++){
        int k=abs(a[i+1]-a[i]);
        if(m>=k*i){
            for(int j=1;j<=i;j++){
                a[j]+=k;

            }
            m-=k*i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]>=a[i]){
                swap(a[j],a[i]);
            }
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1]){
            c++;
        }
    }
    cout<<c+1;
    return 0;
}
