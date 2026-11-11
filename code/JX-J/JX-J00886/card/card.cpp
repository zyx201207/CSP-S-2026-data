#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool z[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n , m;
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d" , &a[i]);
    }
    for(int j = 1 ; j <= n ; j++){
        stack<int> s1;
        for(int i = j ; i <= n ; i++){

            if(z[a[i]] == 0){
                s1.push(a[i]);
                z[a[i]] = 1;
            }
            else{
                while(!s1.empty() && s1.top() != a[i]){
                    z[s1.top()] = 0;
                    s1.pop();
                }
                z[s1.top()] = 1;
            }
        }
        while(!s1.empty()){
            int t = s1.top();
            ans[t]++;
            z[t] = 0;
            s1.pop();
        }
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
