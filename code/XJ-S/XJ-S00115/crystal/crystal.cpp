#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long LL;
LL a[N],s[N];
LL n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+n+1);
    int ans = 1;
    for(int i = 1;i <= n;i++){
        s[i] = a[i] + s[i-1];
        //cout << s[i] << ' ';
    }
    //cout << "<<<\n";
    for(int i = 1;i <= n;i++){
        int L = 1,R = i;
        while(L < R){
            int mid = ((L+R)>>1);
            LL shd = (i-mid+1) * a[i],fct = s[i] - s[mid-1],d = shd-fct;
            //cout << L << ' ' << R << ' ' << mid << ':' << d << '\n';
            if(d <= m)  R = mid;
            else    L = mid+1;
        }
        //cout << i << ' ' << L << '\n';
        ans = max(ans,i-L+1);
    }
    cout << ans;
    return 0;
}