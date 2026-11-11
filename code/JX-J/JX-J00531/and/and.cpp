#include<iostream>
using namespace std;
int a_m[200005];
int m;

 int w_and(int x,int j){
    int sum = 0;
    if(j == m || x == 0){
        return a_m[j];
    }
    for(int i = j + 1;i < m;i++){
        sum = max((w_and(x - 1,i) & a_m[j]),sum);
    }
    return sum;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin >> m >> n;
    for(int i = 0;i < m;i++){
        cin >> a_m[i];
    }
    cout << w_and(n,0);
}
