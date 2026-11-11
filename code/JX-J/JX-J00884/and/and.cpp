#include<iostream>
using namespace std;
long long e[10100101];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b,c=0,d;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>e[i];
    }
    for(int i=1;i<=a;i++){
        for(int j=i+1;j<=a;j++){
            if((e[j] & e[i])>c){
                c=(e[j] & e[i]);
            }
        }
    }
    cout<<c;
}
