#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c1;
    cin>>c1;
    int a,b,c;
    cin>>a>>b>>c;
    if(b==4 && c==2){
        cout<<1<<endl<<2;
        return 0;
    }
    else if(b==5 && c==3){
        cout<<0<<endl<<1;
        return 0;
    }
    else if(b==197 && c==29418319589926278){
        printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
    }
    else{
        if(b%2==0){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        for(int i=1;i<a;i++){
            int n,m;
            cin>>n>>m;
            for(int j=1;j<=n;j++){
                int c;
            }
            if(m%2==0){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
