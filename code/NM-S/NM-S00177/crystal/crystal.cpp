#include <bits/stdc++.h>
using namespace std;

long long n,m,all_,cnt;
long long a[500005] , b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
        all_+=a[i];
    }
    sort(a+1,a+n+1);
    all_ = ceil(all_/n);
    for (int i = 1;i<=n;i++){
            //cout<<a[i]<<' ';
        if(all_ < a[i]){
            if (a[i]-all_>all_-a[i-1])all_ = a[i-1];
            else all_ = a[i];
    break;
        }
    }
    //cout<<endl;
    //cout<<all_<<endl;
    int k = 1;
    for (int i = 1;i<=n;i++){
                        //cout<<a[i]<<' ';
        if (all_>=a[i]) b[k++] = all_-a[i];
    }
    //cout<<k<<endl;
    sort(b+1,b+k);
    for (int i = 1;i<k;i++){
        //cout<<b[i]<<' ';
        if (m>=b[i]){
            cnt++;
            m-=b[i];
        }
        else break;
    }
    if (m){
        for (int i = k;i<=n;i++){
            if (m>(i+1)*(a[i]-all_)){
                cnt++;
                all_ = a[i];
            }
            else break;
        }
    }
    //cout<<endl;
    cout<<cnt;
    return 0;
}
