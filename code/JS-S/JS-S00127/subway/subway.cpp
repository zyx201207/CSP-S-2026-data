#include<bits/stdc++.h>
using namespace std;
int m,n,c,d,q;
int x,y;
long long ans;
int w[500010];
int k[505];
int a[505][505];
int t[505][505];
int v[500010][505];
bool cmp( pair<long long,int >& a, pair<long long,int>& b){
    return a.first< b.first;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i<=m;i++){
        scanf("%d",w+i);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",k+i);
        for(int j = 1;j<=k[i];j++){
            scanf("%d%d",a[i]+j,t[i]+j);
        }
        v[ a[i][j] ][ i ] = t[i][j];
    }

    for(int i = 0;i<q;i++){
        scanf("%d%d",&x,&y);
        priority_queue< pair<long long,int> /*,vector<pair<long long,first> >*/ > pq;
        pq.push({0,x});
        while(pq.top().first!=y){
            pair<long long ,int> tp;
            tp = pq.top();
            pq.pop();
            for(int j = 0;j<=500;j++){
                if(v[a[tp.first][j]){

                }
            }
        }
        cout << w[x]+w[y]+10;
    }
    return 0;
}


/*
对于所有测试数据,均有:
• 0 ≤ c ≤ 25,1 ≤ n ≤ 500,1 ≤ m ≤ ∑(n,i=1)k  i ≤ 5 × 10 5 ,1 ≤ d ≤ 20,1 ≤ q ≤ 10 5 ;
• 对于所有 v (1 ≤ v ≤ m),均有 1 ≤ w v ≤ 10 9 ;
• 对于所有 i (1 ≤ i ≤ n),均有 1 ≤ k i ≤ m;
• 对于所有 i, j (1 ≤ i ≤ n, 1 ≤ j ≤ k i ),均有 1 ≤ a i,j ≤ m,1 ≤ t i,j ≤ 10 9 ;
• 对于所有 i (1 ≤ i ≤ n),均有 a i,1 , a i,2 , . . . , a i,k i 两两不同;
• 对于所有 v (1 ≤ v ≤ m),经过第 v 个地铁站的线路数均不超过 d;
• 任意两个地铁站都可以通过若干条线路互相到达;
• 对于所有 r (1 ≤ r ≤ q),均有 1 ≤ x r , y r ≤ m,且 x r =
y r 。

*/
