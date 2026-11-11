#include <bits/stdc++.h>
using namespace std;
long long n,m;

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin >> n >> m;
int a[n] = {};
vector<long long> nums = {};
for(int i = 0;i < n;i++){
    cin >> nums[i];
}

int s;

for(int i = 1;i <= n;i++){
    sort(nums[i],nums[i-1]);
    vector.back() >> a[i];
    vector.pop_back();
}
int ans = 0;
for(int i = m;i >= 0;i--){
    ans &= a[i];
}
cout << ans << endl;

return 0;
}
