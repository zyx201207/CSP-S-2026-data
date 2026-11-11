#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5;
int n,m;
long long a[N];
long long andnum;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i<=n; i++){
        cin >>a[i];
    }
    if (m == 1){
        sort(a+1,a+n+1,cmp);
        cout << a[1];
        return 0;
    }
    else if (m == n){
        andnum = a[1];
        for (int i = 2;i<=n;i++){
                andnum &= a[i];
        }
        cout <<andnum;
        return 0;

    }
    else{
        sort(a+1,a+n+1,cmp);
        andnum = a[1];
        int i = 2;
        while(m--){
            andnum &= a[i];
            i++;
        }
        cout <<andnum;
    }



    return 0;
}
