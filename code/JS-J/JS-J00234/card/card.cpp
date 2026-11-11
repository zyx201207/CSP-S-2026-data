#include <bits/stdc++.h>
using namespace std;
struct Str{
    int x, pre, nxt;
}a[500005];//a[i].pre means front i
int num[300005], ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m; cin>>n>>m;
    a[0].nxt = 1;
    a[n+1].pre = n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].x;
        a[i].pre = i-1;
        a[i].nxt = i+1;
    }
    bool q = true;
    while(q == true){
        q = false;
        for(int i = a[0].nxt;i<=a[n+1].pre;i = a[i].nxt){
            if(num[a[i].x]!=0){
                q = true;
                a[a[num[a[i].x]].pre].nxt = i;
                a[i].pre = a[num[a[i].x]].pre;
            }
            num[a[i].x] = i;
        }
        for(int i = a[0].nxt;i<=a[n+1].pre;i = a[i].nxt){
            if(num[a[i].x]!=0)ans[a[i].x]++;
        }
        a[0].nxt = a[a[0].nxt].nxt;
        a[a[0].nxt].pre = 0;
        /*for(int i = a[0].nxt;i<=a[n+1].pre;i = a[i].nxt){
            cout<<a[i].x<<" ";
        }
        cout<<endl;*/
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
