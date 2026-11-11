#include <bits/stdc++.h>
using namespace std;
int n,m;
stack<int> stk;
int card[500050],bucket[500050];
bool vis[500050];
bool flg=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> card[i];
        if(card[i] >= card[i-1])flg = 0;
    }
    if(flg){
        for(int i=1;i<=m;i++)cout << i << ' ';
        return 0;
    }
    for(int st=1;st<=n;st++){
        for(int i=1;i<=m;i++)vis[i] = 0;
        for(int i=st;i<=n;i++){
            if(!vis[card[i]]){
                vis[card[i]] = 1;
                stk.push(card[i]);
            }
            else{
                while(!stk.empty() && stk.top() != card[i]){
                    vis[stk.top()] = 0;
                    stk.pop();
                }
                if(stk.empty()){stk.push(card[i]);vis[card[i]] = 1;}
            }
        }
        while(!stk.empty()){
            bucket[stk.top()] ++;
            //cout << stk.top() << ' ';
            stk.pop();
        }
        //cout << '\n';
    }
    for(int i=1;i<=m;i++)cout << bucket[i] << ' ';
}