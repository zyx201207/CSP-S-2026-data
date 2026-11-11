//SN-S00490 杨济铭 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m,n;
	cin>>n>>m;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m>1e8){
		ll b=abs(a[1]-a[0]);
		ll e=m/b;
		float res=(-1+sqrt(1+8*e))/2;
		if(res=int(res)){
			cout<<res+1;
		}else{
			cout<<floor(res)+1;
		}
	}
	bool g=1;
	while(g){
		for(int i=0;i<n-1;i++){
			g=0;
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				g=1;
			}
		}
	}
	vector<int> res;
	bool f=0;
	for(int i=0;i<n-1;i++){
		ll c=m;int cnt=0;
		while(c>0){
			cnt++;
			c-=cnt*(a[i+cnt]-a[i+cnt-1]);
			//cout<<cnt<<" "<<a[i+cnt]<<" "<<c<<" ";
			if(cnt+i+1>=n){
				f=1;
				break;
			}
		}
		//cout<<endl;
		if(f){
			continue;
			f=0;
		}
		if(c==0){
			cnt+=1;
		}
		res.push_back(cnt);
	}
	for(int i=n-1;i>=0;i--){
		ll c=m;int cnt=0;
		while(c>0){
			cnt++;
			c-=(a[i]-a[i-cnt]);
			if(i-cnt<=n){
				f=1;
				break;
			}
		}
		if(f){
			continue;
			f=0;
		}
		if(c==0){
			cnt++;
		}
		res.push_back(cnt);
	}
	int max=0;
	for(int i=0;i<res.size();i++){
		if(res[i]>max){
			//cout<<res[i]<<" ";
			max=res[i];
		}
	}
	cout<<max;
}
