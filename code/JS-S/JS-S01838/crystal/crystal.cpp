#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int num[N];
int aft[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> num[i];
    }
    sort( num , num + n);
    int l = 0, r = n;
    int mid = (l + r) / 2 ;
    for(int i = 0;i < n;i++){
        aft[i]= abs (num[mid] - num[i]);
    }
    sort(aft , aft + n);
    int cnt = 0,sum = 0;
    while(sum < m){
        sum += aft[l];
        cnt++;
        l++;
    }
    if(sum == m){
        cout<<cnt;
    }else{
        cout<<cnt-1;
    }
    return 0;
}
