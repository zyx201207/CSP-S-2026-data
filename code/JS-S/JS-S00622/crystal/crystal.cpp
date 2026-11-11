#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+3;
const int N1 = 5e3+5;
int n;
long long m;
long long a[N],num[N],pre[N],h[N1];
long long v[N1][N1];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int f = 1;
    int c = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        num[i] = i-1;
        pre[i] = pre[i-1]+num[i];
        if(i != 1)h[i] = a[i]-a[i-1];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++){
        if(i == 2){
            c = a[i]-a[i-1];
            //cout<<c<<" "<<a[i]-a[i-1]<<endl;
        }
        else if(i > 2){
            if(c != (a[i]-a[i-1]))f = 0;
        }
    }
    if(f){
        int ans = 1;
        for(int i = 1;i <= n;i++){
            pre[i]*=c;
            //cout<<pre[i]<<" ";
            if(m >= pre[i])ans = i;
            else break;
        }
        cout<<ans<<endl;
        return 0;
    }
    int ans = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            v[i][j] == 0;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            int x = j-i;
            v[i][j] = h[j]*x + v[i][j-1];
            //cout<<v[i][j]<<" ";
            if(v[i][j] <= m){
                ans = max(ans,j-i+1);
            }
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
