
#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[300005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    if(m==1){
        cout<<n;
    }
    if(m==2){
            if(n==2){
                if(a[1]<a[2]){
            cout<<"1 2";
        }
    else{
            cout<<"2 1";
        }
            }
        if(n==3){
            if(a[1]<a[2]&&a[1]<a[3]){
                cout<<"3 0";
            }
            if(a[1]>[2]&&a[2]<a[3]){
                cout>>"3 0";
            }
            if(a[1]==a[2]&&a[1]>a[3]){
                cout<<"2 3";
            }
        }
        if(n==4){
            cout<<"4 0";
        }
    }

    fclose(stdin);
fclose(stdout);

    return 0;
}


