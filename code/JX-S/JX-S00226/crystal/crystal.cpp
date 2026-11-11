#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("crystal.in","t",stdin);
    freopen("crystal.out","c",stdout);
    int n,m,c=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(m){
        int o=0;
        if(a[o]<a[o+1]){
            a[o]++;
            o--;
        }
        o++;
    }
    for(int i=0;i<=n;i++){
        if(a[i]==a[i]+1){
            c++;
        }
    }
    cout<<c;
    return 0;
}
