#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
bool cmp(long long a,long long b){
    return a > b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m,a[500001],num,cnt = 0,maxn = 0,cha;
    bool dc = true;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i==2){
            cha = a[2]-a[1];
        }
        else{
            if(a[i] - a[i-1] != cha && i != 1){
                dc = false;
            }
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i <= n;i++){
        num = m;
        cnt = 0;
        for(int j = i;j <= n;j++){
            if(num >= a[i]-a[j]){
                cnt++;
                num -= a[i]-a[j];
            }
            else{
                break;
            }
        }
        maxn = max(cnt,maxn);
        if(dc){
            break;
        }
    }
    cout << maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
