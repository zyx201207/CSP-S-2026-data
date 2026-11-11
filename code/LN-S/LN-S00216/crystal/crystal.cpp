#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],cnt=2,sum=0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sum+=a[1];
    while(sum){
        if((sum+m)%a[cnt]!=0 and (sum+m)%a[cnt-1]==0) break;
        else{
            sum+=a[cnt];
            cnt++;
        }
    }
    cnt--;
    cout<<cnt;
    return 0;
}
