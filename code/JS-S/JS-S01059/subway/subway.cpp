#include<bits/stdc++.h>
using namespace std;

int n,cnt;
long long m,a[500005];
long long s[500005];

long long find(int l,int r){
    int q = l;
    bool flag = false;
    while(l <= r){
        long long mid = (l + r) / 2;
        if((mid - q + 1) * a[mid] < s[mid] - s[q-1] + m) {
            if(flag = true) return mid;
            l = mid + 1;
        }
        else if((mid - q + 1) * a[mid] > s[mid] - s[q-1] + m) {
            r = mid - 1;
            flag = true;
        }
        else if((mid - q + 1) * a[mid] == s[mid] - s[q-1] + m){
            if(a[mid+1] == a[mid]) l = mid + 1;
            else return mid;
        }
    }
}

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        s[i] = s[i-1] + a[i];
    }

    for(int i=1;i<=n;i++){
        int maxi = find(i,n) - i + 1;
        if(maxi > cnt) cnt = maxi;
    }

    cout << cnt;

    return 0;
}
