#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+10;
long long a[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long mx = 0;
    for(int i = 1;i <= n;i++){
        long long cnt = 1;
        long long sxd = m;
        for(int j = i-1;j >= 1;j--){
        	long long cha = a[i]-a[j];
            if(cha <= sxd){
                cnt++;
                sxd-=cha;
            }else{
                break;
            }
        }
        mx = max(mx,cnt);
        cout << 1;
    }
    cout << mx;
    return 0;
}
