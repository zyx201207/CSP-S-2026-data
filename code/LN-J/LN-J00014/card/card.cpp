#include<iostream>
using namespace std;
long long num[200005];
long long s[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cout<<n<<' ';
    for(int i=1;i<n;i++){
        cout<<0<<' ';
    }

    return 0;
}
