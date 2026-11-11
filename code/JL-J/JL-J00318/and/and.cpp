#include<bits/stdc++.h>
using namespace std;
int a[100000];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int max=-1000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int p=1;p<=n;p++){
        for(int q=1;q<=n;q++){
            if(max<(p&q)){
                max=(p&q);
            }
        }
    }
    cout<<max;
}
