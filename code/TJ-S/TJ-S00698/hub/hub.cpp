#include <bits/stdc++.h>
using namespace std;

int a[500005];
int x[100005];
int main(){
    // freopen("crystal.in", "r", stdin);
    // freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    // cout << n+1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        x[a[i]]++;
    }
    int k=n/2+1;
    int pos=a[k];
    // cout << k << endl;
    // cout << pos;
    int i=1;
    while(m>0){
        if(m>x[a[k-i]]*(pos-a[k-i])){
            m-=x[a[k-i]]*(pos-a[k-i]);
            x[pos]+=x[a[k-i]];
            // cout << x[a[k-i]] << endl;
            x[a[k-i]]=0;
            i++;
            // cout << i;
            // cout << 1 << ' ' << x[pos] << endl; 
        }
        else{
            int big=m/(pos-a[k-i]);
            x[pos]+=big;
            x[a[k-i]]-=big;
            // cout << big << endl;
            m=0;
            // cout << 2 << ' ' << x[pos] << endl;
        }
    }
    cout << x[pos];
    return 0;
}

