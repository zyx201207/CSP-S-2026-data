#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    
    int n,m;
    int a[1000010];
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
     for(int i = 1;i <= n;i++){
        cout << a[i] <<endl;
    }
}
