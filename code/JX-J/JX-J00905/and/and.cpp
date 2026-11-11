#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[100000],b[10000],max1 = 0,maxmin = 99999,c,d = 0,e;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> e;
        a[i] = e;
    }
    for(int j = 0;j<m;j++){
        for(int i = 0;i<n;i++){
            if(a[i] >= max1&&max1<=maxmin){
                max1 = a[i];
                maxmin = max1;
            }
        }
        b[j] = max1;
    }
    for(int j = 0;j<m;j++){
        if(d == 0){
            c = a[j] & a[j+1];
            d = 1;
        }
        else{
            c = c & a[j+1];
        }
    }
    cout << c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
