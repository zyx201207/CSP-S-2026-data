#include <bits/stdc++.h>
using namespace std;
int cha[50001];
struct node{ //zhi he cishu
    int k;
    int c;
};
int b[30001];
int daan[30001];
int dp[50001];
node a[50001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int flag = 1;
    int flag2 = 1;
    for(int i = 1;i<=n;i++){
        cha[i] = 1;
        int k;
        cin>>k;
        a[i].k = k;
        if (b[k] == 0){
            b[k] = i;
        }
        else if (b[k]!=0){
            flag = b[k];
            b[k] = i;
            flag2 = i;
        }
    }


    for (int i = 1;i<flag;i++){
        cha[i] =0;
    }
    int s = 0;
    for (int i = flag;i<=flag2;i++){
        cha[i] = s+1;
        s++;
    }
    for (int i = flag2+1;i<=n;i++){
        cha[i] = i;
    }
    for (int i = 1;i<=n;i++){
        daan[a[i].k] +=cha[i];

    }
    for (int i = 1;i<=m;i++){
        cout<<daan[i]<<" ";
    }
    return 0;
}
