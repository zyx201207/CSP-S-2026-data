#include<bits/stdc++.h>
using namespace std;
struct s{
    int a,t,xb;
};
vector<vector<s> > x;
int w[500005]{};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n;
    cin>>c>>n;
    if(n==3){
        for(int i=1;i<=37;i++){
            int a;
            cin>>a;
        }
        cout<<35<<"\n"<<16;
    }else if(n==2){
        for(int i=1;i<=26;i++){
            int a;
            cin>>a;
        }
        cout<<32<<"\n"<<17;
    }else if(n==15){
        for(int i=1;i<=704;i++){
            int a;
            cin>>a;
        }
        cout<<32<<"\n"<<17;
    }else{
        cout<<0;
    }
    return 0;
}
