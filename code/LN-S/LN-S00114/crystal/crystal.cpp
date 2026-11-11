#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans=1,i=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(1){
        long long s=abs(a[i+1]-a[i]);
        m-=s;
        if(m<0) break;
        i++;
        ans++;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
