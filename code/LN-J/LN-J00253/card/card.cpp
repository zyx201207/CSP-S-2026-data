#include <bits/stdc++.h>
using namespace std;
const int M = 300005;
const int N = 500005;
int n,m,card[N],sum[M];
bool pos[M];
queue<int>a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    memset(pos,false,sizeof(pos));
    for (int i=1;i<=n;i++) cin >> card[i];
    for (int i=1;i<=n;i++){
        memset(pos,false,sizeof(pos));
        while (a.empty()) a.pop();
        //a.pop();
        for (int j=i;j<=n;j++){
            a.push(card[j]);
            if (pos[card[j]]){
                do{
                    pos[a.front()]=false;
                    a.pop();
                }while (a.front()==card[j]);
            }
            //a.push(card[j]);
            pos[card[j]]=true;
        }
        for (int k=1;k<=m;k++){
            if (pos[k]) sum[k]++;
        }
    }
    for (int i=1;i<=m;i++) cout << sum[i] << " ";
    return 0;
}
