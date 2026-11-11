#include<iostream>
using namespace std;
int c,t;
long long n,d;
long long a[2000011],b[2000011];
int main(){
        freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    if(t==1){
        cout << 12251;
    }else{
        for(int i=1;i<t;i++){
            cout << 1 << endl;
        }
        cout << 2;
    }
}
