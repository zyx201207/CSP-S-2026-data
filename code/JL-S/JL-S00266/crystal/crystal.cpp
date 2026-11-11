#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=m;i++){
        ++a[i];
        for(int j=0;j<=m;j++){
            if(++a[i]==a[j]) sum++;
        }
    }
    cout<<sum;
    fclose("crystal.in");
    fclose("crystal.out");
    return 0;
}
/*小 R 有 n 颗能量水晶,其中第 i (1 ≤ i ≤ n) 颗的能量值为整数 a i 。
小 R 想用其中若干颗能量水晶合成一颗大水晶,用于合成的水晶必须具有相同的
能量值。小 R 希望参与合成的水晶尽可能多。他可以进行 至多
. m 次操作。每次操作可
以任选一颗水晶,将其能量值增加 1;同一颗水晶可以被重复选择。
你需要帮助小 R 求出,进行至多 m 次操作后,他最多能用多少颗能量水晶合成一
颗大水晶。
Oct31==Dec25?
*/
