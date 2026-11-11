#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    int a[4]={0,2,2,2};
    cout<<upper_bound(a,a+3,1)-a;
    return 0;
}
