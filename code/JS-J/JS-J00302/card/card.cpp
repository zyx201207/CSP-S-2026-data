#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
stack<int>st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[a[i]]++;
        if(b[a[i]]==1){
            cnt++;
        }
    }
    for(int i=1;i<=m;i++){
        b[a[i-1]]--;
        if(b[a[i-1]]==0){
            cnt--;
        }
        cout<<cnt<<" ";
    }
    return 0;
}
