#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int end_=1,cnt=1,ans=1;
    for(long long j=2;j<=n;j++){
        if(((j-1)*(a[j]-a[j-1])) <=m){
            m-=(j-1)*(a[j]-a[j-1]);
            ans++;
            end_=j;
        }
        else break;
    }
    cnt=ans;
    for(int i=1;i<=n+1-ans;i++){
        m+=a[end_]-a[i];
        cnt--;
        for(long long j=end_+1;j<n;j++){
            if(((j-i-1)*(a[j]-a[j-1]))<=m){
                m-=(j-i-1)*(a[j]-a[j-1]);
                cnt++;
            }
            else{
                end_=j-1;
                ans=(int(max(ans,cnt)));
                break;
            }

        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
