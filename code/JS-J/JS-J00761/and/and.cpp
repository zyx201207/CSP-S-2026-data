#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    int a;
    int g;
    int b;
    long long h = 0;
    int ans = 0;
    cin >> n >> m;
    int ab[n];
    long long maxl = -1;
    for(int i = 0;i < n;i++){
        cin >> ab[i];
    }
    if(m == 1){
        for(int i = 0;i < n;i++){
            if(ab[i] > maxl){
                maxl = ab[i];
            }
        }
        cout << maxl;
        return 0;
    }
    if(m == n){
        for(int i = 0;i < n;i++){
            ans = 0;
            a = ab[i];
            b = h;
            while(max(a,b) > 0){
                if(a % 2 == 1 && b % 2 == 1){
                    g = 1;
                }else{
                    g = 0;
                }
                h += g * pow(2,ans);
                ans++;
                a /= 2;
                b /= 2;
            }
        }
        cout << h;
        return 0;
    }
    if(m == 2){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                h = 0;
                if(j != i){
                    ans = 0;
                    a = ab[i];
                    b = ab[j];
                    while(max(a,b) > 0){
                        if(a % 2 == 1 && b % 2 == 1){
                            g = 1;
                        }else{
                            g = 0;
                        }
                        h += g * pow(2,ans);
                        ans++;
                        a /= 2;
                        b /= 2;
                    }
                }
                if(h > maxl){
                    maxl = h;
                }

            }
        }
        cout << maxl;
        return 0;
    }
    if(m == n - 1){
        for(int i = 0;i < n;i++){
            h = 0;
            for(int j = 0;j < n;j++){
                if(j != i){
                    ans = 0;
                    a = ab[j];
                    b = h;
                    while(max(a,b) > 0){
                        if(a % 2 == 1 && b % 2 == 1){
                            g = 1;
                        }else{
                            g = 0;
                        }
                    h += g * pow(2,ans);
                    ans++;
                    a /= 2;
                    b /= 2;
                    }
                }
            }
            if(h > maxl){
                maxl = h;
            }
        }
        cout << maxl;
        return 0;
    }
    return 0;
}
