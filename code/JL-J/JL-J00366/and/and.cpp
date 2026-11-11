#include<bits/stdc++.h>
using namespace std;
int n = 0 , m = 0 , maxn = 0;
int a[200010];
int v[200010];
void dfs(int an , int step){
    if(step >= m){
        maxn = max(maxn , an);
    }else{
        for(int i = 1 ; i <= n ; i++){
            if(step == 0){
				v[i] = 1;
				dfs(a[i] , step + 1);
				v[i] = 0;
			}
            else if(v[i] == 0){
                v[i] = 1;
                dfs(an & a[i] , step + 1);
                v[i] = 0;
            }
        }
    }
}
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    dfs(0 , 0);
    cout << maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
