#include<bits/stdc++.h>
using namespace std;
const int R = 1010;
int a[R];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i = 1;i <= t;i++){
        int n,m;
        cin>>n>>m;
        cout<<n/(m+1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
