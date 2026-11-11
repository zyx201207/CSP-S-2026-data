#include <bits/stdc++.h>
using namespace std;
long long n,m,z = 0;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n);
    bool flag = true;
    for(int i = 0;i < n - 1;i++){
        b[i] = a[i+1] - a[i];
    }
    for(int i = 1;i < n-1;i++){
        if(b[i] != b[i-1]) flag = false;
    }
    if(flag){
        long long t = b[0];
        long long g = m,z = 0;
        for(int i = t;i <= m;i += t){
            if (g >= i){
                z++;
                g -= i;
            }
            else break;
        }
        cout << z;
    }

    else{
        long long z = 0;
        for(int i = 0;i < n;i++){
            long long caoz = m;
            long long result = 0,sum = 0;
            for(int j = i-1;j >= 0;j--){
                long long gh = b[j];
                gh += sum;
                if(gh <= caoz){
                    result++;
                    caoz -= gh;
                    sum = gh;
            }
                else break;
        }
             z = max(z,result);}
        cout << z + 1;
    }
    return 0;
}
