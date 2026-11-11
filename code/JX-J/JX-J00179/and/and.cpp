#include <iostream>
using namespace std;
int D(int n,int listi[1000000],int lene){
    int listi2[1000000];
    if (n==1){
        return lene;
    }
    for (int i = 0;i<=lene;i++){
        listi2[i] = listi[i+1];
    }
    return D(n - 1,listi2, lene - 1) + lene - 1;}
int main(){
    int n=0,m=0,maxand=0,and=0,li[1000000] = {0};
    freopen("and.in","r",stdin);
    cin >> n >> m;
    for (int i = 0;i<n;i++){
        cin >> li[n];}
    cout << D(m,li,n);
    freopen("and.ans","W",stdout);
    return 0;}
