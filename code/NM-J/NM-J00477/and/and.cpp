#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m, sum;
    cin>> n >> m;
    int a[n];
    for(int i = 0;i < n;i ++) cin>>a[i];
    for(int i = 0;i < n;i ++){
        int num = 0;
        for(int y = 0;y < n-1;y ++){
            if(a[y] < a[y+1])
            {
                num = a[y];
                a[y] = a[y+1];
                a[y+1] = num;

            }
        }
    }
    sum = a[0];
    for(int i = 1;i < m;i ++){
        sum = sum &  a[i];
    }
    cout<<sum;
    return 0;
}
