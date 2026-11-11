#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int inp[500005];
bool wte[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        cin >>inp[i];
    }
    for(int i = 1;i <= n;i++){
        deque <int>q;
        for(int j = i;j <= n;j++){
            if(!wte[inp[j]]){
                  q.push_back(inp[j]);
                  wte[inp[j]] = true;
            }
            else{
                while(q.back() != i){
                    int a = q.back();
                    q.pop_back();
                    wte[a] = false;
                }
            }
        }
    for(int i = 1;i <= m;i++){
        cout <<ans[i];
        if(i != n)
            cout <<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
