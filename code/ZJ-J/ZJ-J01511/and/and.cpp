#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=INT_MIN;
vector<int> v;
void bl(int ceng,int ad,int last_i){
	if(ceng==0){
		for(int i=1;i<=n;i++){
			bl(1,a[i],i);
		}
	}
	else{
		if(ceng==m){
			v.push_back(ad);
			return;
		}
		else{
			for(int i=last_i+1;i<=n;i++){
				bl(ceng+1,ad&a[i],i);
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		int now=a[i];
		for(int j=i+1;j<i+m;j++){
			now=now&a[j];
		}
		ans=max(ans,now);
	}
	bl(0,0,0);
	for(auto p:v){
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}