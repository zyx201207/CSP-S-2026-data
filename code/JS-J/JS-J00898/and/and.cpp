#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005];
bool check(int x,int cnt=0){
    for(int i=0;i<n;i++){
        if((a[i]&x)==x){
            ++cnt;
        }
    }
    return cnt>=m;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=30;i>=0;i--){
        if(check(ans+(1<<i))){
            ans+=1<<i;
        }
    }
    cout << ans;
}
