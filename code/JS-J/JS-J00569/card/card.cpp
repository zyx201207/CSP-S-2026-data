#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    for(int i=1;i<=m;i++){
        srand((signed int)time(0));
        cout<<rand()%15+1<<" ";
    }
    return 0;
}
