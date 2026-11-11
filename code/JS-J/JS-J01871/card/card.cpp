#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    cout<<a[n];
    return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
//4 3
//1 2 1 3
//if(a[n])->a[n-1] F
//1......n
//cout<<a[n]>f;