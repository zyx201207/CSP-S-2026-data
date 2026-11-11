#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1) cout<<n;
    else if(m==2){
        int c=0,b=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) c++;
            else if(a[i]==2) b++;
            if(a[n]==1) c++;
            else if(a[n]==2) b++;
            if(a[i]==a[n] && a[i]==1) c--;
            else if(a[i]==a[n] && a[i]==2) b--;
        }
        cout<<c<<" "<<b;
    }
    return 0;
}
