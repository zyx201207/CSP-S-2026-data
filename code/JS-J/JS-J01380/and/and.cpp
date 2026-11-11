#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const int maxai = (1<<21) + 1;
int n, m;
int a[maxn];
int srtnum[maxai];
int minn = 0x3f3f3f3f, maxx = 0;
bool cmp(int ai1, int ai2){
    return ai1 > ai2;
}
int ans = 0;
void dfs(int mnum, int summ){
    if(mnum == m){
        ans = max(ans, summ);
        return ;
    }
    if(summ < ans){
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(srtnum[a[i]] == 0){
            continue;
        }
        srtnum[a[i]]--;
        if(mnum == 0){
            dfs(mnum + 1, a[i]);
        }else{
            dfs(mnum + 1, summ & a[i]);
        }
        srtnum[a[i]]++;
    }
    return ;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < minn){
            minn = a[i];
        }
        if(a[i] > maxx){
            maxx = a[i];
        }
        if(a[i] < maxai){
            srtnum[a[i]]++;
        }
    }
    if(maxx < maxai){
        ans = maxx;
        int j = 0;
        for(int i = maxx; i >= minn; i--){
            if(srtnum[i] == 0){
                continue;
            }
            if(ans & i == 0){
                ans = i;
                j += srtnum[i];
                continue;
            }
            ans = ans & i;
            j += srtnum[i];
            if(j >= m){
                break;
            }
        }
        if(j < m){
            ans = 0;
        }
    }else{
        sort(a+1, a+n+1, cmp);
        ans = a[1];
        for(int i = 2; i <= m ; i++){
            ans = ans & a[i];
        }
    }

    if(ans == 0){
        if(maxx < maxai){
            sort(a+1, a+n+1, cmp);
        }
        dfs(0,0);
    }

    cout << ans << endl;

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
