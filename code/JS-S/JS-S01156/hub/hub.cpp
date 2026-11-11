#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

int c,t;
bool flag;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(flag){
            cout<<1<<"\n";
            flag=false;
        }
        else{
            cout<<2<<"\n";
            flag=true;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

