#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300001],n,m,k;
int z[500005][300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",.stdout);
    cin >> n >> m;
    int d = 0;
    int k = n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int s;
    for(int i = 1;i <= n;i++){
            d++;
        while(k >= n){
            z[d][i] = a[i];
        }
        s += k;
        k--;
    }
    int h = 1;int sum = 0;
    int hk = 1;
   for(int i = 1;i <= s;i++){
        for(int i= 1;i <= n;i++){

            hk++;
              h++;
            if(z[s][h] == z[s][i]){
                for(int j = 1;j <= i - h;j++){
                    z[s][i] == 0;
                             }
                             for(int i = 1;i <= n;io++){
                                sum += a[i];
                                if(sum == i)
                                    ans[hk] = sum;
                             }
            }

        }

   }
   for(int i = 1;i <= m;i++){
            cout << ans[i];
        }
    fclose(stdin);
    fclose(stdout);
}
