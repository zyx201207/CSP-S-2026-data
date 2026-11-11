#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> a;
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a.resize(n + 5);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    //submit 6
    if(m == 1){
        cout << 0;
        return 0;
    }
    //submit 8-10
    if(m == 2){
        int maxn = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x = a[i] & a[j];
                maxn = max(x, maxn);
                //cout << a[i] << " " << a[j] << " " << x << endl;
            }
        }
        cout << maxn << endl;
        return 0;
    }
    //submit 1-5 without head
    if(m == 3){
        int maxn = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    int x = a[i] & a[j] & a[k];
                    maxn = max(x, maxn);
                    //cout << a[i] << " " << a[j] << " " << x << endl;
                }
            }
        }
        cout << maxn << endl;
        return 0;
    }


    if(m == 4){
        int maxn = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int o = k + 1; o < n; o++){
                        int x = a[i] & a[j] & a[k] & a[o];
                        maxn = max(x, maxn);
                        //cout << a[i] << " " << a[j] << " " << x << endl;
                    }
                }
            }
        }
        cout << maxn << endl;
        return 0;
    }

    if(m == 5){
        int maxn = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int o = k + 1; o < n; o++){
                        for(int p = o + 1; p < n; p++){
                            int x = a[i] & a[j] & a[k] & a[o] & a[p];
                            maxn = max(x, maxn);
                            //cout << a[i] << " " << a[j] << " " << x << endl;
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
        return 0;
    }

    if(m == 6){
        int maxn = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int o = k + 1; o < n; o++){
                        for(int p = o + 1; p < n; p++){
                            for(int q = p + 1; q < n; q++){
                                int x = a[i] & a[j] & a[k] & a[o] & a[p] & a[q];
                                maxn = max(x, maxn);
                                //cout << a[i] << " " << a[j] << " " << x << endl;
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
        return 0;
    }

    if(m == 7){
        int maxn = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int o = k + 1; o < n; o++){
                        for(int p = o + 1; p < n; p++){
                            for(int q = p + 1; q < n; q++){
                                for(int r = q + 1; r < n; r++){
                                    int x = a[i] & a[j] & a[k] & a[o] & a[p] & a[q] & a[r];
                                    maxn = max(x, maxn);
                                    //cout << a[i] << " " << a[j] << " " << x << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
        return 0;
    }
    return 0;
}