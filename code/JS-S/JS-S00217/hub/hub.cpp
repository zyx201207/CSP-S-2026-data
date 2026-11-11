#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll n,c,t,d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>t;
    while(t--){
        srand(time(0));
        cout<<rand()%(10*(rand()%10));
    }
    return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
