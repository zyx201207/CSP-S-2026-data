#include<bits/stdc++.h>
using namespace std;
const int M = 3e5+5;
const int N = 5e5+5;
int n,m;
int f[M];
int ans[M];
bool ff[M];
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    //cout<<"---";
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        //cout<<i<<endl;
    }
    int T = 1;
    while(T <= n){
        stack<int> sta;
        memset(f,0,sizeof(f));
        memset(ff,0,sizeof(ff));
        for(int i = T;i <= n;i++){
            int x = a[i];
            if(f[x]){
                while(!sta.empty() && sta.top() != x){
                    f[sta.top()]--;
                    sta.pop();
                }
            }
            else{
                sta.push(x);
                f[x]++;
            }
            //cout<<i<<"  ";
            //for(int p = 1;p <= m;p++)cout<<f[p]<<" ";
            //cout<<endl;
        }
        //cout<<T<<endl;
        while(!sta.empty()){
            //cout<<sta.top()<<" ";
            if(!ff[sta.top()]){
                ff[sta.top()] = 1;
                ans[sta.top()]++;
            }
            sta.pop();
        }
        //cout<<endl;
        T++;
    }
    for(int i = 1;i <= m;i++)cout<<ans[i]<<" ";

    return 0;
}
