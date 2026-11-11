#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10005];
int s[10005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        s[i] = a[i]&a[i-1];
    }
    sort(s+1,s+n+1,cmp);
    cout << s[1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
