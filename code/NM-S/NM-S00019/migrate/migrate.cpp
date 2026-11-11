#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c=0;
    int t=0;
    int G=0;
    cin>>c>>t;

    if(c==11||c==12){
        int n=0;
        int t=0;
        cin>>n>>t;

        int dao[n];
        for(int a=0;a<n;a++){
            cin>>dao[a];
        }

        int chajv[n-1];
        for(int a=0;a<n;a++){
            chajv[a]=dao[a+1]-dao[a]

            if(chajv[0]<=t/n){
                cout<<2n-1<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }

            if(chajv[0]<=t/n){
                cout<<2n-1<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
    }
    else{
        return 0;
    }

    return 0;
}
