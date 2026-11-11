#include<bits/stdc++.h>
using namespace std;
int n[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>n[i];
    }
    sort(n+1,n+a+1);
    int cnt=n[a];
    for(int i=a-1;i>a-b;i--){
        cnt=cnt&n[i];
    }
    cout<<cnt;
    return 0;
}

