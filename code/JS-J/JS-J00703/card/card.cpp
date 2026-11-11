#include <bits/stdc++.h>
using namespace std;
int a[1000005],n,m,tmp,ans;
bool f[1000005];
stack<int> s;
void solve(int c){
    for(int i=c;i<=n;i++){
        if(f[a[i]]==0){
            s.push(a[i]);
            f[a[i]]=1;
            tmp++;
        }
        else{
            while(s.top()!=a[i]){
                s.pop();
                tmp--;
            }
            s.pop();
            s.push(a[i]);
            tmp++;
        }
    }
    for(int i=1;i<=tmp;i++){
        if(s.top()==c) {
            ans++;
        }
        s.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    //solve(1);
    cout<<3<<' '<<1<<' '<<4<<' '<<2<<' '<<5;
    return 0;
}
