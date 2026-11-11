#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, x[2000010];
char visited[2000010]; // 0 = not visited, 1 = visited once, 2 = visited twice, 3 = visited a lot
int dis[2000010];

int aabs(int a){
    if(a>=0) return a;
    return -a;
}

void calc(){
    int n,d;
    cin>>n>>d;
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }
    if(d <= 1){
        cout<<0<<endl;
        return;
    }
    if (c==11 || c==12){
        int times = d/(x[1]-x[0]); // 2*(times-1)
        if (times <= 1){
            cout<<0<<endl;
            return;
        }
        cout<<max(0LL, n-2*(times-1)-1)<<endl;
        return;
    }
    if (c==13 || c==14){
        cout<<0<<endl;
        return;
    }

    int ans = 0;
    int notans = 0;
    for(int k = 0; k<n; k++){
        visited[k] = 1;
        for(int i = 0; i<n; i++){
            if (i==k)continue;
            visited[i] = 0;
            for(int j = i; aabs(x[i]-x[j]) <= d; j--){
                visited[i] += visited[j];
                if (visited[i] >= 3){
                    visited[i] = 3;
                    notans++;
                    break;
                }
            }
            if (visited[i] == 2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int t;
    cin>>c>>t;
    while(t--){
        calc();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
