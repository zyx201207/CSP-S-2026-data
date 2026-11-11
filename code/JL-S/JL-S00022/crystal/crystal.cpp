#include<bits/stdc++.h>
using namespace std;
long long a[500000];
long long n,m,last,maxx,sum,nn,mm,lastt,x;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (long long i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for (long long i = n - 1;i >= 0;i--){
        mm = m;
        sum = 0;
        for (long long j = 0;j < n - 1;j++){

            x = a[i] - a[j];
            mm -= x;
            if (mm < 0){
                j = n;
            }
            sum++;
            if(sum > maxx){
                maxx = sum;
            }
            if (a[i] < a[j+1]){
                j = n;
            }
        }
    }
    cout << maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
