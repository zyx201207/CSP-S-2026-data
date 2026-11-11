#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int m,n,k;
int a[MAXN],ans[MAXN];
    bool b[MAXN];
stack<long long> r;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i =0;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i =n-1;i>=0;i--){
        for(int j =0;j<=i;j++){
                int cnt=a[j];
                while(b[cnt]==true){
                    if(r.top()==cnt){
                        r.pop();
                        b[cnt]=false;
                    }
                    else{
                        r.pop();

                    }
                }
                r.push(cnt);
                b[cnt]=true;
            }
            while(!r.empty()){
                cout<<r.top();
                ans[r.top()]+=1;
                r.pop();
            }
        }
    }
