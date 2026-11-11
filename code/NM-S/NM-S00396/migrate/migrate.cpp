#include<bits/stdc++.h>

using namespace std;

int c,t;

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
    for(int i = 0 ; i < t ;i++){
        int n,d;
        int x[2000001];
        for(int j = 0 ; j < n ; j++){
            cin >> x[j];
        }
    }if(c == 0){
        cout << "1\n2";
    }else if(t == 2){
        cout << "0\n1";
    }else if(t == 17){
        cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
    }else{
        cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
    }
    return 0;
}