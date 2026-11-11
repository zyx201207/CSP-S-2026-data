#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5 , M = 3e5+5;
int a[N],ans,n,m,cnt[M];
bool inst[M],again[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    stack<int> s;

    for(int i = n-1;i >= 0;i--){
        for(int j = i;j < n;j++){
            if(!inst[a[j]]){
                s.push(a[j]);
                inst[a[j]]=1;
            }
            else {

                while(s.top() != a[j]){
                    int t = s.top();
                    s.pop();
                    inst[t] = 0;
                }
            }
        }
        while(!s.empty()){
            int t = s.top();
            cnt[t]++;
            s.pop();
        }
        memset(inst , 0 , sizeof(inst));
    }
    for(int i = 1;i <= m;i++)cout << cnt[i] << " ";
    return 0;
}
