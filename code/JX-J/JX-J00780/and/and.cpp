#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    if(m==1){
        for(int i=1;i<=n;i++){
            sum=max(sum,a[i]);
        }

    }
    cout<<sum;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
