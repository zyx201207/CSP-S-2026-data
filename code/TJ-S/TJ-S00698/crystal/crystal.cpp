#include <bits/stdc++.h>
using namespace std;

int a[500005];
int x[100005], y[100005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i]>0)  x[a[i]]++;
        else  y[a[i]]++;
    }
    sort(a+1, a+n+1);
    int k=n/2+1;
    int pos=a[k];
    int i=1;
    while(m>0){
        if(m>x[a[k-i]]*(pos-a[k-i])){
            m-=x[a[k-i]]*(pos-a[k-i]);
            x[pos]+=x[a[k-i]];
            x[a[k-i]]=0;
            i++;
        }
        else{
            int big=m/(pos-a[k-i]);
            x[pos]+=big;
            x[a[k-i]]-=big;
            m=0;
        }
    }
    cout << x[pos];
    return 0;
}

