#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long maxs = 0;
long long fm(long long a[]){
    long long maxp = 0;
    int j = 0;
    for (int i = 1;i <= n;i++){
        if (maxp < a[i]){
            maxp = a[i];
            j = i;
        }
    }
    a[j] = 0;
    return maxp;
}
int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    maxs = fm(a);
    for (int i = 1;i <= m-1;i++)
        maxs = maxs & fm(a);

    cout << maxs;
    return 0;
}
