#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[MAXN];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    long long dazhi;
    if(m == 1){
        cout << a[0];
    }
    else if(m == 2){
        long long yu = 0;
        dazhi = a[yu] & a[yu+1];
        yu++;
        while(dazhi == 0){
            dazhi = a[yu] & a[yu+1];
            yu++;
        }
        cout << dazhi;
    }
    else{
        dazhi = a[0] & a[1];
        for(int i = 2;i < m;i++){
            dazhi = dazhi & a[i];
        }
        cout << dazhi;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
