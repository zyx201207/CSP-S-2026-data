#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N];
bool b = true;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i] - a[i-1] != 1) b = false;
    }
    if(b){
        for(int i=0;i<m;i++){
            cout<<m-i<<' ';
        }
    }
    cout<<"\n";
    return 0;
}
