/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
set<int>s;
stack<int>stk;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        s.clear();
        int cnt=0;
        while(!stk.empty())stk.pop();
        for(int j=1;j<=n;j++){
            for(int k=i;k<=n;k++){
                if(!s.count(a[k])){
                    s.insert(a[k]);
                    stk.push(a[k]);
                    cerr<<'/';
                }else{
                    while(stk.top()!=a[k]){
                        stk.top();
                        s.erase(s.find(stk.top()));
                        stk.pop();
                    }
                }
            }
            while(!stk.empty()){
                if(stk.top()==i){
                    cnt++;
                    break;
                }
                if(!stk.empty())stk.pop();
            }
        }
        cout<<cnt<<' ';
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int a;
    for(int i=1;i<=m;i++)cout<<a%n<<' ';
    return 0;
}
