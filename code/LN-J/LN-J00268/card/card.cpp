#include<bits/stdc++.h>
using namespace std;
const int R = 500010;
stack<int> dg;
bool M[R];
int a[R],ans[R];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int o = 1;o <= n;o++){
        for(int i = o;i <= n;i++){
            if(M[a[i]]){
                while(dg.top() != a[i]){
                    M[dg.top()] = 0;
                    dg.pop();
                }
            }else{
                dg.push(a[i]);
                M[dg.top()] = 1;
            }
        }
        for(int i = 1;i <= m;i++){
            if(M[i] == 1){
                M[i] = 0;
                ans[i]++;
                dg.pop();
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
