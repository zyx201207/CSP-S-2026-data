#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long mus[5000005];
long long summ[5000005];
vector <int>inp;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long a,b;
    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        inp.push_back(a);
    }
    sort(inp.begin(),inp.end());
    for(int i = 1;i <= n;i++){
        mus[i] = inp[i] - inp[i - 1];
    }
    summ[1] = mus[1];
    for(int i = 2;i <= n;i++){
        summ[i] = summ[i - 1] + mus[i];
    }
    int l = 1,r = 1;
    int sum = summ[1];
    int ans = -1e9;
    while(r < n){
        while(sum < m && r < n){
            r++;
            sum += summ[r];
        }
        int lth = r - l;
        if(lth > ans)
            ans = lth;
        if(l < r){
         sum -= summ[l];
            l++;
        }
    }
    cout << ans + 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
