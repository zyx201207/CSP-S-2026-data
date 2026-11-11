#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],q[500005],need[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;


    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)
        q[i] = a[i] - a[i - 1];
    for(int i = 1;i <= n;i++){
        need[i] = q[i] * (i - 1) + need[i - 1];
        //cout << need[i] << " ";
    }
    //cout << n << " " << m << endl;
    int l = 1,r = n;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(need[mid] <= m)
            l = mid;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}
//676767676767676767676767
