#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+1] = {};
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    int max_ans = -1;
    for(int i=1;i<=n;i++){
        int ans = 1;
        int mm = m;
        for(int j=i+1;j<=n;j++){
            if(a[i] - a[j] <= mm){
                mm -= a[i] - a[j];
                ans ++;
            }
            else{
                break;
            }
        }
        max_ans = max(max_ans,ans);
    }
    cout << max_ans;
    return 0;
}
