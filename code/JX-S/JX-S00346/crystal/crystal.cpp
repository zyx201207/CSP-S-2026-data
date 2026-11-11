#include<bits/stdc++.h>
using namespace std;

int n,m,a[5010],sum;
void dfs(int no,int ma,int ans,int ha){
    if(ans > m){
        return ;
    }
    if(no == n){
        sum = max(ha,sum);
        return ;
    }
    if(ma >= a[no]){
        dfs(++no,ma,ans-a[no]+ma,++ha);
    }
    dfs(++no,ma,ans,ha);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = a[0] ; i <a[n-1] ; i++){
        dfs(0,i,0,0);
    }
    cout << sum;
    return 0;
}
