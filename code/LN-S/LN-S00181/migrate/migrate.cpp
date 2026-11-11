#include <iostream>
#include <cstdio>
using namespace std;
long long n,d,a[2000001];
bool found(long long j,long long k){
    if(k-j == 2){return false;}
    if(found(j+1,k)||found(j,k-1)){
        return false;
    }
    int tempcnt = 0;
    if(a[j] + d >= a[j+2] && a[j+1] + d >= a[k]){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int i = 1;i <= t;i++){
        cin >> n >> d;
        long long cnt = 0;
        for(long long j = 1;j <= n;j++){
            cin >> a[j];
        }
        for(long long j = 1;j <= n-3;j++){
            for(long long k = j+3;k <= n;k++){
                if(found(j,k)){
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
