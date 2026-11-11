#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200001],n,k = 0,l = 0,ai = 1,bi = 1,m = 0,h = 0;
    string b[200001];
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        cin >> b[i];
        h += a[i];
    }
    bi = n;
    if (a[ai] > a[bi]){
        if (b[ai] != b[bi]){
            k += a[bi];
        }
        l = a[ai] - a[bi];
        m = 1;
        bi--;
    }
    else{
        if (b[ai] != b[bi]){
            k += a[ai];
        }
        l = a[bi] - a[ai];
        m = 0;
        ai++;
    }
    while(ai <= h / 2 && bi >= h / 2){
        if (m == 0){
           if (l < a[ai]){
                if (b[ai] != b[bi]){
                    k += l;
                }
                l = a[ai] - l;
                m = 1;
                bi--;
            }
            else{
                if (b[ai] != b[bi]){
                    k += a[ai];
                }
                l = l - a[ai];
                m = 0;
                ai++;
            }
        }
        else{
            if (l < a[bi]){
                if (b[ai] != b[bi]){
                    k += l;
                }
                l = a[bi] - l;
                m = 0;
                ai++;
            }
            else{
                if (b[ai] != b[bi]){
                    k += a[bi];
                }
                l = l - a[bi];
                m = 1;
                bi--;
            }
        }
    }
    cout << k;
    fclose(stdin);
    fclose(stdout);
}
