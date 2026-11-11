#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
int a[N];
vector<int>ve[50];
int sz[50];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        a[i]=x;
        int cnt = 0;
        while(x){
            if(x%2){
                ve[cnt].push_back(i);
                sz[cnt]++;
            }
            x/=2;
        }
    }
    for(int i = 30;i >= 0;i++){
        if(sz[i] == m){
            int ans = ve[i][0];
            for(auto it:ve[i]){
                ans&=it;
            }
        }else{
            cout << 0;
        }
    }
    return 0;
}
