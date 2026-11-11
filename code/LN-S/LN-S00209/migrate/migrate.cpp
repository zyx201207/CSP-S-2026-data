#include<iostream>
using namespace std;
int c,t;
long long n,d;
long long a[2000011],b[2000011];
int main(){
        freopen("mlgrate.in","r",stdin);
    freopen("mlgrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        long long y=a[2]-a[1];
        if(d<2*y){
            cout << 0;
        }else{
            long long h=d/y;
            h*=2;
            if(n<h){
                cout << 0;
            }else{
                cout << n-h+1;
            }
        }
        cout << endl;
    }
}
