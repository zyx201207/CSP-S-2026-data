#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    char a[13];
    char b;
    int t = 1;
    int n = 0;
    int m = 0;
    int l1[200050],l2[200050];
    int inx = 0;
    int ans = 0;
    cin >> a;
    cin >> b;
    for (int i = 0; i<=12; i++){
        if (a[i] == " " && t == 1){
            for (int j = 0; j<=i-1; j++){
                n += pow(10,i-j-1)*a[j];
            }
            for (int j = i+1; j<=a.len()-1; j++){
                m += pow(10,a.len()-j-1)*a[j];
            }
        }
    }
    for (int i = 0; i<=b.len(); i++){
        if (b[i] == " "){
            l1[inx] = i;
            inx++;
        }
    }
    for (int i = 0; i<=l1[0]; i++){
        l2[0] += pow(10,l1[0]-i-1)*b[i];
    }
    for (int i = 0; i<=n-1; i++){
        for (int j = 0; j<=l1[i+1]-l1[i]-2; j++){
            l2[i+1] += pow(10,l1[i+1]-l1[i]-2-j)*b[l1[i]+j+1];
        }
    }
    sort(l2,l2+n);
    cout << l2[n-1];
    return 0;
}
