#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    int n;
    int m;
    int ai;
    char ci;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ai;
        cin>>ci;
        k+=ai;
    }
    cout<<k/2;
    return 0;
}
