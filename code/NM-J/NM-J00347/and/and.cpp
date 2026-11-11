#include <bits/stdc++.h>
using namespace std;
int a[200099];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    int y=a[0];
    for(int i=1;i<m;i++){
        int t=y&&a[i];
        y=t;
    }
    cout<<y<<" "<<a[0]<<" "<<a[1]<<" "<<a[0]&&a[1];
    return 0;
}
