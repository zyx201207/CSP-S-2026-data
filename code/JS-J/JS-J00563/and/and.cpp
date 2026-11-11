#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m,a[N],cnt;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[m-1];

    fclose(stdin);
    fclose(stdout);
    return 0;
}

