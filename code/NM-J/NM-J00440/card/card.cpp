#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,j=0;
    cin>>n>>m;
    vector<int> a(n+1,0);
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]){
            sum[j]++;
        }else{
            j++;
        }
    }
    for(int i=0;i<j;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
