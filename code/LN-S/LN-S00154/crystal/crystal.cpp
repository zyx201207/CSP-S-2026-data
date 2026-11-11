#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l=n-1,r=n-1;
    long long res=m;
    while(r>0){
		while(res>0){
			if(l!=0) l--;
			res-=(a[r]-a[l]);
		}
        if(res<0){
            res+=(a[r]-a[l]);
            l++;
        }
		int cnt=r-l+1;
		ans=max(ans,cnt);
        if(l<r){
            res+=(a[r]-a[r-1])*(r-l);
            r--;
        }
        else{
            r--;
            l=r;
        }
	}
	cout<<ans;
    return 0;
}
