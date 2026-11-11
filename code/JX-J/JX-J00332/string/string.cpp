#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 250000;

ll a[maxn][2];
char c[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i][1] >> c[i];
        a[i][0] = a[i-1][1];
        a[i][1] = a[i][0]+a[i][1];
        //cout << a[i][0] << ' ' << a[i][1] << endl;
    }
    ll s = a[n][1];
    ll sum = 0;
    for(int i = 1,j = n;a[i][0] < s/2 and a[j][1] > s/2 and j>i;){
        if(a[i][0] > s-a[j][0]){
            //sum += (a[j][1]-a[j][0])*(c[i]!=c[j]);
            j--;
        }else if(a[i][1] < s-a[j][1]){
            //sum += (a[i][1]-a[i][0])*(c[i]!=c[j]);
            i++;
        }else{
            sum += min(a[i][1]-a[i][0],a[j][1]-a[j][0])*(c[i]!=c[j]);
            //cout << i << ' ' << j;
            int p = i,q = j;
            if(a[p][1] <= s-a[q][0]){
                a[q][1] = s-a[p][0];
                i++;
            }
            if(a[p][1] >= s-a[q][0]){
                a[p][0] = s-a[q][1];
                j--;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
