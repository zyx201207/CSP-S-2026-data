#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[200005];
cin >> n >> m;
for(int i = 1;i <= n;i++){
    cin >> a[i];
}
sort(a + 1, a + 1 + n);
int maxa = -1;
for(int i = 1;i <= m;i++){
    for(int j = 1;j <= n;j++){
        for(int l = i;l <= j;l++){
            if(l == j) continue;
            maxa = max(maxa,a[j]&a[l]);
        }
    }
}
cout << maxa;
return 0;
}
