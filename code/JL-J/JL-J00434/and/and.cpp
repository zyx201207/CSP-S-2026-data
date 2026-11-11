#include<iostream>
using namespace std;

int main(){
//    reopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);

    int n,m,max_n=0;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;i<n;i++){
            max_n=max(max_n,a[i] & a[j]);
        }
    }
    cout << max_n;
    return 0;
}
