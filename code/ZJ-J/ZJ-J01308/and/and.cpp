#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005];
vector<int>vec;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];vec.push_back(i);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j:vec){
			if(a[j]>>i&1)cnt++;
		}
		if(cnt>=k){
			vector<int>tmp;tmp.clear();
			for(int j:vec)
				if(a[j]>>i&1)tmp.push_back(j);
			vec=tmp;
			ans+=(1<<i);
		}
	}
	cout<<ans<<'\n';
	return 0;
}//9:43 100pts

