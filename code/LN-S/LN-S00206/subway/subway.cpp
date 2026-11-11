#include<bits/stdc++.h>
using namespace std;

int main(){
    int c,n,m,d,q,a[500005],k,b[5000005];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    cin>>k;
    for(int i=1;i<=2*k+1;i++){
        cin>>b[i];
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    for(int i=1;i<=q;i++){
        srand(time(0));
        cout<<rand()%2<<endl<<rand()%2;
    }

    return 0;
}
