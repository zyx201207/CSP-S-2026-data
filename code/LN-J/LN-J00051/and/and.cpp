#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200001];
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    long long maxn = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j){
                if(a[i] & a[j] > maxn){
                    maxn = a[i] & a[j];
                }
            }
        }

    }
    cout << maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
