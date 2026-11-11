#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);

    int a,b,d=0,d1=0;
    int c[200005];
    cin>>a>>b;
    for (int i=0;i<a;i++){
        cin>>c[i];
    }
    for (int i=0;i<a;i++){
        d1=0;
        for (int l=i+1;l<a;l++){
            d1=max(d1,(c[i] & c[l]));
        }
    d=max(d,d1);
    }
    cout<<d;
    return 0;
   fclose(stdin);
   fclose(stdout);
}
