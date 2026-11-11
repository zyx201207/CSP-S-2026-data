#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
int b[200005],flag,flagg;

int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    if(m=2){
        for(int i = 1;i<=n-1;i++){
            for(int j = i+1;j<=n;j++){
                flag = max(flag,(b[i]&b[j]));
            }
        }
    }


    cout<<flag;
    return 0;
}
