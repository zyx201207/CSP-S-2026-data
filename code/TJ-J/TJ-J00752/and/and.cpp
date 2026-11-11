#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],t,p,maxv = 0;
string x[200005],c[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        while(a[i] / 2 != 0){
            int cnt=0;
            cnt++;
            b[i] += (a[i] % 2)*(cnt*10);
        }
    }
    for(int i = 1;i <= n;i++){
        x[i] = b[i] + '0';
    }
    if(n == 1){
        cout << a[n];
        return 0;
    }
    for(int i = n;i > 1;i--){
        p += i;
    }
    for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i - 1;j++){
                for(int w = max(x[i].size(),x[j].size());w >= 0;w--){
                    if(b[i] == b[j]){
                        maxv =max(maxv,b[i]);
                    }else{
                        if((x[i][w] == '0'&& x[j][w] == '0' )|| (x[i][w] == '1'&& x[j][w] == '1')){
                            c[i*j][w] == '1';
                            int ti = 1;
                            for(int v = 1;v <= max(x[i].size(),x[j].size()) - w - 1;v++){
                                ti *= 2;
                            }
                            t += ti;
                        }else{
                            c[i*j][w] ==  '0';
                        }
                    }
                    if(w == 0){
                        maxv=max(maxv,t);
                    }
                    t = 0;
                }
            }
    }
    cout << maxv;
    return 0;
}
