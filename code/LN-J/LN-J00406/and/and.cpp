#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    int ans = 0;
    if(m == 2){
        for(int i = 1; i <= n - 1; i++){
            for(int j = i + 1; j <= n; j++){
                ans = max((a[i] & a[j]) , ans);
            }
        }
    }

    if(m == 3){
        for(int i = 1; i <= n - 2; i++){
            for(int j = i + 1; j <= n - 1; j++){
                for(int k = j + 1; j <= n; k++){
                    ans = max((a[i] & a[j] & a[k]) , ans);
                }
            }
        }
    }


    if(m == 5){
        for(int i = 1; i <= n - 4; i++){
            for(int j = i + 1; j <= n - 3; j++){
                for(int k = j + 1; j <= n - 2; k++){
                    for(int q = k + 1; q <= n - 1; q++){
                        for(int w = q + 1; w <= n; w++){
                            ans = max((a[i] & a[j] & a[k] & a[q] & a[w]) , ans);
                        }
                    }
                }
            }
        }
    }

    if(m == 6){
        for(int i = 1; i <= n - 5; i++){
            for(int j = i + 1; j <= n - 4; j++){
                for(int k = j + 1; j <= n - 3; k++){
                    for(int q = k + 1; q <= n - 2; q++){
                        for(int w = q + 1; w <= n - 1; w++){
                            for(int e = w + 1; e <= n; e++){
                                ans = max((a[i] & a[j] & a[k] & a[q] & a[w] & a[e]) , ans);
                            }
                        }
                    }
                }
            }
        }
    }

    if(m == 8){
        for(int i = 1; i <= n - 7; i++){
            for(int j = i + 1; j <= n - 6; j++){
                for(int k = j + 1; j <= n - 5; k++){
                    for(int q = k + 1; q <= n - 4; q++){
                        for(int w = q + 1; w <= n - 3; w++){
                            for(int e = w + 1; e <= n - 2; e++){
                                for(int r = e + 1; r <= n - 1; r++){
                                    for(int t = r + 1; t <= n; t++){
                                        ans = max((a[i] & a[j] & a[k] & a[q] & a[w] & a[e] & a[r] & a[t]) , ans);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    if(m == 10){
        for(int i = 1; i <= n - 9; i++){
            for(int j = i + 1; j <= n - 8; j++){
                for(int k = j + 1; j <= n - 7; k++){
                    for(int q = k + 1; q <= n - 6; q++){
                        for(int w = q + 1; w <= n - 5; w++){
                            for(int e = w + 1; e <= n - 4; e++){
                                for(int r = e + 1; r <= n - 3; r++){
                                    for(int t = r + 1; t <= n - 2; t++){
                                        for(int y = t + 1; y <= n - 1; y++){
                                            for(int u = y + 1; u <= n - 1; u++){
                                                ans = max((a[i] & a[j] & a[k] & a[q] & a[w] & a[e] & a[r] & a[t] & a[y] & a[u]) , ans);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(m == 15){
        for(int i = 1; i <= n - 14; i++){
            for(int j = i + 1; j <= n - 13; j++){
                for(int k = j + 1; j <= n - 12; k++){
                    for(int q = k + 1; q <= n -11; q++){
                        for(int w = q + 1; w <= n - 10; w++){
                            for(int e = w + 1; e <= n - 9; e++){
                                for(int r = e + 1; r <= n - 8; r++){
                                    for(int t = r + 1; t <= n - 7; t++){
                                        for(int y = t + 1; y <= n - 6; y++){
                                            for(int u = y + 1; u <= n - 5; u++){
                                                for(int o = u + 1; o <= n - 4; o++){
                                                    for(int p = o + 1; p <= n - 3; p++){
                                                        for(int s = p + 1; s <= n - 2; s++){
                                                            for(int d = s + 1; d <= n - 1; d++){
                                                                for(int f = d + 1; f <= n - 1; f++){
                                                                    ans = max((a[i] & a[j] & a[k] & a[q] & a[w] & a[e] & a[r] & a[t] & a[y] & a[u] &a[o]&a[p]&a[s]&a[d]&a[f]) , ans);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<ans;

    return 0;
}
