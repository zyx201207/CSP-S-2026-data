#include<iostream>
#include<vector>
using namespace std;
struct island{
    unsigned long long pos;
    unsigned long long paths=0;
};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    int t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n;
        unsigned long long d;
        cin>>n>>d;
        vector<island>ild(n);
        for(int j=0;j<n;j++){
            cin>>ild[j].pos;
        }
        int exit=0;
        for(int j=1;j<n-1;j++){
            if(ild[j].pos-ild[j-1].pos!=ild[j+1].pos-ild[j].pos){
                exit=1;
                break;
            }
        }
        if(exit==0){
            if(d>=2*ild[1].pos-ild[0].pos){
                cout<<n-2;
            }
            else{
                cout<<0;
            }
        }
    }
}
