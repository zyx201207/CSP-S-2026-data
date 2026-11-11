#include<bits/stdc++.h>
using namespace std;
long long arr[800000];
long long ans[800000];
long long ansr = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    long long n,m;
    cin >> n >> m;

    for(int i = 1;i<=n;i++){
        cin >> arr[i];

    }
    sort(arr+1,arr+n+1);
    ans[1] = 0;
    for(int i = 2;i<=n;i++){
        ans[i] = arr[i] - arr[i-1];
    }
    for(int i = 1;i<=n;i++){
        long long ansrt = 1;
        long long cost = m;
        for(int j = i+1;j<=n;j++){
            if((cost - ans[j]*ansrt)>=0){
                cost -= ans[j]*ansrt;
                ansrt++;
            }
            else{
                ansr = max(ansr,ansrt);
                break;
            }
        }
    }
    cout << ansr << '\n';
}
