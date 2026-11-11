#include<bits/stdc++.h>
#define N 200005
#define int long long//原来内存限制1个G吗，这还说啥了全给我long long
using namespace std;
int n,a[N],b[N];
int cnt,ans;
vector<int> f;
char c[N],d[N];
char finda(int k){
    int l = 1, r = n;
    int res;
    while(l<=r){
        int mid = (l + r) >> 1;
        if(a[mid]>=k){
            r = mid - 1;
            res = mid;
        }else{
            l = mid + 1;
        }
    }
    return c[res];
}
char findb(int k){
    int l = 1, r = n;
    int res;
    while(l<=r){
        int mid = (l + r) >> 1;
        if(b[mid]>=k){
            r = mid - 1;
            res = mid;
        }else{
            l = mid + 1;
        }
    }
    return d[res];
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        b[n-i+1]=a[i];
        d[n - i + 1] = c[i];
        cnt += a[i];
    }
    for (int i = 1; i <= n;i++){
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        if(a[i]==b[i]){
            f.push_back(a[i]);
        }else{
            f.push_back(a[i]);
            f.push_back(b[i]);
        }
    }
    sort(f.begin(), f.end());
    // for(int i : f){
    //     cout << i << " ";
    // }
    // cout << endl;
    int l = 1;
    for(int r : f){
        if(finda(l)!=findb(l))
            ans += r - l + 1;
        l = r + 1;
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}//rp++!