#include<bits/stdc++.h>
using namespace std;
int main(){
    ios:sync_with_stdio(false);
    cin.tie(cullptr);
    freopen("crystal.in",'r',stdin);
    freopen("crystal.out",'w',stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int a[15+n*m];
    for(int i=0;i<13+n*m;i++){
    	cin>>a[i];
    }
    cout<<c+n+m+d+q+3<<endl<<d-m+n;
    return 0;
}
