#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int b[500010]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(b[a[i]]>=3){
            cout<<n-1<<" ";
        }
        else if(b[a[i]]>=2){
            cout<<n<<" ";
        }
        else{
            cout<<"1"<<" ";
        }
    }
    return 0;
}
