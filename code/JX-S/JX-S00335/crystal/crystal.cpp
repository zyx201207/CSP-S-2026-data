#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
vector<int> d;
int n,m;
bool check(int x){
    for(int i=x;i<=n;i++){
        if(d[i]-d[i-x]-(i-x)*(a[i]-a[i-x])<=m){
            return 1;
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a.resize(n+1),d.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        d[i]=(a[i]-a[i-1])*(i-1)+d[i-1];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    // for(int i=1;i<=n;i++){
	// 	cout<<d[i]<<" ";
	// }
	// cout<<"\n";
    cout<<l-1;
    return 0;
}
//g++ crystal.cpp -o crystal -std=c++14
//freopen()
/*
 * hi i want to be looked in jx mihuo code show
 * my luogu id mc2djwh
 * easy t1!
 * 15:00 done t1
 * i want to baoli with every t2-t4
 * but i didn't read problem
 * 16:30 omg i ac t2!!!
 * just a floyd ,i think it's a binary graph or sth
 * 18:00
 * finally,i can't write baoli in t3
 * www
 * i write an dijkstra but it doesn't work
 * and i forget priority_queue
 * so i have to did it by my hand
 * /
