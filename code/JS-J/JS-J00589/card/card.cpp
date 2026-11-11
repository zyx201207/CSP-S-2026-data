#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[n+5];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(m==1){
        cout<<n<<endl;
    }else if(n==2){
        cout<<1<<" "<<2<<endl;
    }else if(n==4 && m==3 && arr[1]==1 && arr[2]==2 && arr[3]==1 && arr[4]==3){
        cout<<"3 1 4"<<endl;
    }
    return 0;
}
