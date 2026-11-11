#include<bits/stdc++.h>
using namespace std;


int intwo(int a){
    int s=0;
    while(a/2){
        int n=a%2;
        if(n==1){
            s++;
        }
    }
    return s;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        int x=0;
        for(int i=0;i<n;i++){
            if(a[i]>x){
                x=a[i];
            }
        }
        cout<<x;
        return 0;
    }
    int A[n];
    for(int i=0;i<n;i++){
        A[i]=intwo(a[i]);
    }
    int x=0.y;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(A[j]>x){
                x=A[j];
                y=j;
            }
        }
    }
    cout<<a[y];
    return 0;
}
