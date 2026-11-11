#include<bits/stdc++.h> 
using namespace std;
long long t1,num,ans,n,m,a[200005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=n-1;i>0;i--){
		int t=m;
		t1=i-1;
		num=1;
		while(t>=0){
			if(t1>=0){
				t-=(a[i]-a[t1]);
				num++;
				t1--;
			}else{
				if(t1==-1){
					num++;
					break;
				}
			}
		}ans=max(ans,num-1);
		if(ans>=i){
			break;
		}
	}cout<<ans;
	return 0;
}