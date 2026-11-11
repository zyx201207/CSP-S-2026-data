#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=m;i++){
        if(i==1){
            sum=a[i];
        }
        else sum&=a[i];
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
