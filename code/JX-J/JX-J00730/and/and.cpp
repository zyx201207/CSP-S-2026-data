#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m=1){
        for(int i=0;i<n;i++){
            cinj>>a[i];
        }
        sort(a,a+n-1);
        cout<<a[n-1];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
