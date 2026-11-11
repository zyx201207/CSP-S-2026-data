#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,num[N],apper[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int t;
            for(int z=1;z<=j-i;z++){
                if(apper[z]==t);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<n<<' ';
    }
    return 0;
}
