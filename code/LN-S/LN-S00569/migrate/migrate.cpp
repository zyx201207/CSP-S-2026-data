#include <bits/stdc++.h>

using namespace std;

long long x[789113];
long long n,d;
vector<int> p;
int minn;
int ans;

void dfs(int m,int r){
    if(m == r){
        if(minn == p.size()+1){
            ans ++;
        }
        else{
            if(minn > p.size()+1){
                ans = 0;
                minn = p.size()+1;
            }
        }
        return;
    }

    if(minn < p.size()+1) return;
    for(int i=m+1;i<=r-1;i++){
        if(x[i] - x[i-1] > d) return;

        p.push_back(i);

        dfs(i,r);

        p.pop_back();
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate,out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin >> c >> n;
    for(int i=1;i<=t;i++){
        cin >> n >> d;
        for(int j=1;j<=n;j++){
            cin >> x[j];
        }
        int sum = 0;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                ans = 0;
                minn = 9999999;
                while(!p.empty()) p.pop_back();
                dfs(j,k);
                if(ans == 2) sum ++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
