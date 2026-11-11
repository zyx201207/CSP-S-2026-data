#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int daan(int x){
    int dx=0;
    int s[200005];
    int i=0;
    string y={0};
    while(x){
      i++;
      s[i]=x%2;
      x/=2;
    }

    for(int j=i;j>=1;j++) {
        y+=a[j];
    }
    cout<<y;
}


int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        cout<<daan(a[i])<<" ";
    }
    return 0;
}
