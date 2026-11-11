#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<char> c;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
        int x;
        char y;
        cin >> x >> y;
        a.push_back(x);
        c.push_back(y);
    }
    long long l=0,r=n-1;
    while(r>l){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }else if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }else {
            r--;
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}