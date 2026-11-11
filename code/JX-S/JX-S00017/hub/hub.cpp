include <bits/stdc++.h>
using namespace std;

int cifang(int a,int b){
    int c=1;
    for(int i=0;i<b;i++){
        c*=a;
    }
    return c;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,k,x=0;
        cin>>n>>k;
        int a[n-1],b[n-1];
        for(int j=0;j<n-1;j++){
            cin>>a[j]>>b[j];
        }
        while((cifang(4,x)+1)<n){
            x++;
        }
        cout<<x;
    }
    return 0;
}
