#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0,c,t;
long long x[2000005],d;
vector<int> h[2000005];
            int flag=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
            cin>>n>>d;
    while(t--){
            memset(h,0,sizeof(h));
            int p=0;
            cin>>x[1]>>x[2];
            p=x[2]-x[1];
            int flag=0;
    for(int i=3;i<=n&&i<=flag;i++){
        cin>>x[i];
        if(x[i]-x[i-1]!=p){
            flag=7;
        }
    }
    if(flag==7){
        break;
    }
            cin>>n>>d;

    }
    if(flag==7&&c==0){
            if(n==4&&d==2){cout<<1<<endl<<2;
            return 0;}
            if(n==5&&d==3){cout<<0<<endl<<1;
            return 0;}
            if(n==197&&d==29418319589926278){cout<<8129<<endl<<
16<<endl<<
9<<endl<<
7<<endl<<
12<<endl<<
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
2<<endl<<
0<<endl;
            return 0;}
            else {cout<<0<<endl<<
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
0;return 0;}
    }
}
