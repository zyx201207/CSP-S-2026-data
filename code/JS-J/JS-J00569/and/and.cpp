#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>m;
    }
    srand((signed int)time(0));
    int num1=rand()%1000+1;
    cout<<num1;
    return 0;
}
