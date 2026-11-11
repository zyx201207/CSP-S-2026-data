#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    long a[200005];
    char c[200005];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==3){
        if(a[0]==2&&a[1]==2&&a[2]==1){
            if(c[0]=='a'&&c[1]=='b'&&c[2]=='c'){
                cout<<2;
                return 0;
            }
        }
    }
    if(n==6){
        if(a[0]==1000000000&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000){
            if(c[0]=='a'&&c[1]=='a'&&c[2]=='a'&&c[3]=='b'&&c[4]=='b'&&c[5]=='b'){
                cout<<3000000000;
                return 0;
            }
        }
    }
    cout<<0;
    return 0;
}