#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n,m;
int main(){
    //3.01
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int cnt = 0;
    int ls = 0;
    for(int i = 0;i<n;i++){
        cin>>ls;
        a.push_back(ls);
    }
    int cha = a[1]-a[0];
    int j = cha;
    for(int i = n-2;i>=0;i--){
        cha = a[i+1]-a[i];
        if(m >= j) {
            cnt++; 
            m = m - j;
        }
        j = j+cha;
    }
    cout<<cnt+1;
    return 0;
}