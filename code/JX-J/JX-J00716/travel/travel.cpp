#include<iostream>
#include<cmath>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,a1,b,b1;
    char ac,bc;
    cin>>a>>a1>>ac>>b>>b1>>bc;
    if(a==b){
        cout<<1;
        if(a1==b1){
            cout<<1;
            int maxc=max(ac-'A',bc-'A'),minc=min(ac-'A',bc-'A');
            if(maxc!=3){
                cout<<1;
                if(maxc-minc==1)cout<<1<<endl;
                else cout<<0<<endl;
            }else{
                cout<<"00"<<endl;
            }
        }else{
            cout<<"000"<<endl;
        }
    }else{
        cout<<"0000"<<endl;
    }

    return 0;
}
