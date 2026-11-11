#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 6;
int arr[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;

    for(int i = 1;i <= n;i ++) cin >> arr[i];

    for(int i = 1;i <= n;i ++) cout << n - i + 1 << " ";

    return 0;
}