#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[n-1];
    return 0;
}
