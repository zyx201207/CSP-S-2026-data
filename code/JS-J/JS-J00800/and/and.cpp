#include<bits/stdc++.h>
using namespace std;
long long b[40],total[40],total2[40];
long long l[200010],l2[200010];
int check(int x){
    for(int i = 32;i >= 0;i--){
        if(x >= b[i])return i;
    }
}
bool cmp(int x,int y){
    return x > y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    b[0] = 1;
    for(int i = 1;i <= 32;i++){
        b[i] = b[i-1]*2;
    }
    int n,m;
    cin >> n >> m;
    long long a[200010];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        total[check(a[i])]++;
    }
    int cnt;
    for(int i = 32;i >= 1;i--){
        total2[i] = total2[i+1]+total[i];
        if(total2[i] >= m){
            cnt = b[i];
            break;
        }
    }
    int j = 0,p = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] >= cnt) l[++j] = a[i];
        if(a[i] >= cnt&&a[i] < cnt*2) l2[++p] = a[i];
    }
    sort(l+1,l+j+1,cmp);
    sort(l2+1,l2+p+1,cmp);
    int ans1;
    for(int k = 1;ans1 == 0&&k<=m;k++){
            ans1 = l[k];
        for(int i = k;i <= m;i++){
            ans1 &= l[i];
        }
    }
    int ans2 = l[1];
    if(p >= m){
        for(int i = 1;i <= p-m+1;i++){
            ans2 &= l2[i];
        }
    }else{
        ans2 = 0;
    }
    cout << max(ans1,ans2);
}
