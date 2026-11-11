#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m,a[1000000];
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int and1 = a[m-1];
    for(int i = m-2;i>=0;i--){
        and1 = and1 and a[i];
    }
    cout << and1;
    return 0;
}

