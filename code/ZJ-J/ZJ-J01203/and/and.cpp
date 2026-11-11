#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;cin>>n;
    int m;cin>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxand=0;
    for(int i=0;i<n-m+1;i++){   
        int posand=a[i];
        for(int j=i;j<i+m;j++){
            posand=posand&a[j];
        }
        if(posand>maxand){
            maxand=posand;
        }
    }
    cout<<maxand;
    return 0;
}