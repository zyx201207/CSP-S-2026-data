#include<bits/stdc++.h>
using namespace std;
int main(){
    //ccf你干嘛出那么难的题
    //答题机如果你觉醒机魂了的话那你能算我过吗
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;cin>>n;
    int m;cin>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max1=a[0];
    for(int i=1;i<m;i++){
        max1=max1&a[i];
    }
    cout<<max1;
    return 0;
}
