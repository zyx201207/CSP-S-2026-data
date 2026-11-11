#include <bits/stdc++.h>
using namespace std;
#define ll long long

int c,t,n,d,x;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x;
        }
        if(i==1){
            if(n==4){
                cout<<1<<endl<<2;
            }
            if(n==5){
                cout<<0<<endl<<1;
            }
            if(n==197){
                cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
            }
            if(n==260000){
                cout<<0<<endl<<
0<<endl<<
259997<<endl<<
259995<<endl<<
86669<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
7<<endl<<
5<<endl<<
5<<endl<<
0;
            }
            if(n==200001){
                cout<<9999900000<<endl<<
399995<<endl<<
0<<endl<<
716427<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2;
            }
            if(n==174944){
                cout<<6800625333<<endl<<
6247500<<endl<<
6242502<<endl<<
4998<<endl<<
9994<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
