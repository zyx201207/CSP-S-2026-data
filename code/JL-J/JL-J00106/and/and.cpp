#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ull unsigned long long
#define pb push_back
#define mii map<int,int>
#define pii pair<int,int>
#define si stack<int,int>
#define qi queue<int,int>
#define miao return 0;
using namespace std;

const signed int N = 2e5+5;

int n,m;
int a[N];
int ans = -1;

bool cmp(int x,int y){
    return x > y;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a,a+n,cmp);

    int an = a[0];
    for(int i=1;i<m;i++){
        an = an & a[i];
    }

/*
    for(int i=0;i<n-m+1;i++){
        int ad = a[i];
        for(int j=i;j<m;j++){
            ad = ad & a[j];
        }
        ans = max(ans,ad);
    }
*/
    cout << an << endl;

    miao
}