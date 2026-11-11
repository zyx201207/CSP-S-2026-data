#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int n, m, e = 0, k, c = 1, a[n+5];
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort (a+1,a+n+1);
    for(int j = 1;j<=m;j++){
        if (e == 0){
            e++;
            k++;
        }
        else if(e == a[c+1]){
            e++;
            k++;
            c++;
        }else if(e == a[c]){
            e++;
        }else{
            break;
        }
    }
    cout<<k;
    return 0;
    //fclose(stdin);
    //fclose(stdout);

}
