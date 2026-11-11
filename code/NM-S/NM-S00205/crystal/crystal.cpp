#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,num=0;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=n; i>0; i--){
        int b=m;
        while(b>=0){
            if(a[i-1]+b==a[i]){
                m-=b;
                num++;
                b--;
            }
            else{
                b--;
            }
        }
    }
    cout << num+1;
    return 0;
}
