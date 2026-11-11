#include <bits/stdc++.h>
using namespace std;
long long n,m,result;
long long a[200005];
bool cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n,cmp);
    if(m == 1){
        result = a[0];
    }
    else if(m == n){
        long long re = a[0] & a[1];
        for(int i = 2;i < n;i++){
            re = re & a[i];
        }
        result = re;
    }
    else{
        result = a[0] & a[1];
        for(int i = 2;i < m;i++){
            result = result & a[i];}
    }
    cout << result;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
