#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005],ans,cnt;
string c,d,zong;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        ans+=a[i];
    }
    //for(int i=n-1;i>=0;i--){
        //b[n-i-1]=a[i];
        //d[n-i-1]=c[i];
   // }
    for(int i=0;i<n;i++){
        for(int j=1;j<=a[i];j++){
            zong+=c[i];
        }
    }
    for(int i=0;i<ans/2;i++){
        if(zong[i]!=zong[ans-i-1])cnt++;
    }
    cout<<cnt;
    return 0;
}
