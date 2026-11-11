#include <bits/stdc++.h>
using namespace std;

int n , m;
int a[500010];
int b[500010];
bool f[300010];
int len = 0;
int ans[300010];
bool flag = 0;

int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] < a[i - 1]){
            flag = 1;
        }
    }
    if(flag == 0){
        for(int i = 1;i <= m;i++){
            cout << i << " ";
        }
        return 0;
    }
    for(int i = 1;i <= n;i++){
        len = 0;
        memset(b , 0 , sizeof(b));
        memset(f , 0 , sizeof(f));
        for(int j = i;j <= n;j++){
            if(f[a[j]] == 0){
                f[a[j]] = 1;
            }else{
                for(int k = j - 1;;k--){
                    if(f[a[k]] == 0){
                        continue;
                    }
                    f[a[k]] = 0;
//                    cout << len << " " << b[len] << endl;
                    b[len] = 0;
                    len--;
                    if(a[k] == a[j]){
                        f[a[k]] = 1;
                        break;
                    }
                }
            }
            len++;
            b[len] = a[j];
        }
//        cout << len << endl;
        for(int j = 1;j <= len;j++){
            ans[b[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
