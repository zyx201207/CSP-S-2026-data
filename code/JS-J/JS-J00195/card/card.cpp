#include<bits/stdc++.h>
using namespace std;
vector <int> a;
int n,m,cnt=0;
int q[200005];
int x[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>q[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int p=1;p<=n;p++){
                if(a[p]==q[j]){
                    for(int i=p+1;i<=cnt;i++)
                        a.pop_back();
                    cnt-=cnt-p-1;
                }
                else{
                     a.push_back(q[j]);
                     cnt++;
                }
            }
        }
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=m;j++){
                if(a[i]==j){
                    x[j]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<x[i]<<' ';
    }
    cout<<endl;
    return 0;
}
