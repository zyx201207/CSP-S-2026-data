#include<bits/stdc++.h>
using namespace std;
int dqc[1000005];
int qzh(int n){
    if(n==0){
        return dqc[0];
    }
    int k=0;
    for(int i=0;i<n;i++){
        k+=dqc[i]*n-i;
    }
    return k;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    vector<int> a;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.insert(a.begin()+i,t);
    }sort(a.begin(),a.end());

    for(int i=0;i<=n;i++){
        dqc[i]=a[i+1]-a[i];
        int t=qzh(i);
        if(t>=m){
            cout<<i+1;
            return 0;
        }
    }
	return 0;
}
