#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool b[200010];
int ans = 0, t = 1;
int n, m;
void dfs(int x, int ma){
    if(x > m){
        ans = max(ans, ma);
        return;
    }
    if(t > n - m + 1) return;
    for(int i = t; i <= n; i ++){
        if(b[i] == true){
            b[i] = false;
            if(x == 1) ma = a[i];
            else ma = ma & a[i];
            x ++;
            dfs(x, ma);
            b[i] = true;
            t ++;
        }
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        b[i] = true;
    }
    if(m == n){
        for(int i = 1; i <= n; i ++){
            if(i = 1) ans = a[i];
            else ans = ans & a[i];
        }
        cout << ans << '\n';
        return 0;
    }else if(m == 1){
        for(int i = 1; i <= n; i ++) ans = max(ans, a[i]);
        cout << ans << '\n';
        return 0;
    }else if(m == 2){
        for(int i = 1; i <= n - 1; i ++){
            for(int j = i + 1; j <= n; j ++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << '\n';
        return 0;
    }else if(m == 3){
        for(int i = 1; i <= n - 2; i ++){
            for(int j = i + 1; j <= n - 1; j ++){
                for(int k = j + 1; k <= n; k ++){
                    ans = max(ans, a[i] & a[j] & a[k]);
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }else if(m == 4){
        for(int i = 1; i <= n - 3; i ++){
            for(int j = i + 1; j <= n - 2; j ++){
                for(int k = j + 1; k <= n - 1; k ++){
                    for(int ii = k + 1; ii <= n; ii ++){
                        ans = max(ans, a[i] & a[j] & a[k] & a[ii]);
                    }
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }else if(m == 5){
        for(int i = 1; i <= n - 4; i ++){
            for(int j = i + 1; j <= n - 3; j ++){
                for(int k = j + 1; k <= n - 2; k ++){
                    for(int ii = k + 1; ii <= n - 1; ii ++){
                        for(int jj = ii + 1; jj <= n; jj ++){
                            ans = max(ans, a[i] & a[j] & a[k] & a[ii] & a[jj]);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }else if(m == 6){
        for(int i = 1; i <= n - 5; i ++){
            for(int j = i + 1; j <= n - 4; j ++){
                for(int k = j + 1; k <= n - 3; k ++){
                    for(int ii = k + 1; ii <= n - 2; ii ++){
                        for(int jj = ii + 1; jj <= n - 1; jj ++){
                            for(int kk = jj + 1; kk <= n; kk ++){
                                ans = max(ans, a[i] & a[j] & a[k] & a[ii] & a[jj] & a[kk]);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }else if(m == 7){
        for(int i = 1; i <= n - 6; i ++){
            for(int j = i + 1; j <= n - 5; j ++){
                for(int k = j + 1; k <= n - 4; k ++){
                    for(int ii = k + 1; ii <= n - 3; ii ++){
                        for(int jj = ii + 1; jj <= n - 2; jj ++){
                            for(int kk = jj + 1; kk <= n - 1; kk ++){
                                for(int iii = kk + 1; iii <= n; iii ++){
                                    ans = max(ans, a[i] & a[j] & a[k] & a[ii] & a[jj] & a[kk] & a[iii]);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }else if(m == 8){
        for(int i = 1; i <= n - 7; i ++){
            for(int j = i + 1; j <= n - 6; j ++){
                for(int k = j + 1; k <= n - 5; k ++){
                    for(int ii = k + 1; ii <= n - 4; ii ++){
                        for(int jj = ii + 1; jj <= n - 3; jj ++){
                            for(int kk = jj + 1; kk <= n - 2; kk ++){
                                for(int iii = kk + 1; iii <= n - 1; iii ++){
                                    for(int jjj = iii + 1;jjj<=n;jjj++){
                                        ans = max(ans, a[i] & a[j] & a[k] & a[ii] & a[jj] & a[kk] & a[iii]&a[jjj]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
        return 0;
    }else if(m==9){
        for(int i=1;i<=n-8;i++){
            for(int j=i+1;j<=n-7;j++){
                for(int k=j+1;k<=n-6;k++){
                    for(int ii=k+1;ii<=n-5;ii++){
                        for(int jj=ii+1;jj<=n-4;jj++){
                            for(int kk=jj+1;kk<=n-3;kk++){
                                for(int iii=kk+1;iii<=n-2;iii++){
                                    for(int jjj=iii+1;jjj<=n-1;jjj++){
                                        for(int kkk=jjj+1;kkk<=n;kkk++){
                                            ans=max(ans,a[i]&a[j]&a[k]&a[ii]&a[jj]&a[kk]&a[iii]&a[jjj]&a[kkk]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}
