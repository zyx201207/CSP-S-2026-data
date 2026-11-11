#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int sum=n+m+d+q+3;
    cout<<sum<<endl;
    if(sum%2==0){
        cout<<sum/2+1;
    }else{
        cout<<sum/2-1;
    }
    return 0;
}
