#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;

//Question: Select m numbers from n numbers(total)

int a[200005];
int dp[200005];//dp[i] for select i from n
//Extended: dp[200005][200005]

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);//may i use it?
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {

        }
    }


    return 0;
}
