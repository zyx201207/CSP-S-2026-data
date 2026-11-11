#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int e[35];
vector<int> vec[200005];
void solve(void){
	int n,m;cin>>n>>m;
	if(n==m){
		int ans=(1LL<<31)-1;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			ans&=a;
		}
		cout<<ans<<endl;
		return;
	}
	e[0]=1;
	for(int i=1;i<=30;i++){
		e[i]=e[i-1]*2;
	}
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i];
		for(int j=30;j>=0;j--){
			if(e[j]<=t){
				t-=e[j];
				vec[i].push_back(j);
			}
		}
	}
	int t[35];
	bool st[35];
	for(int i=1;i<=n;i++){
		for(auto j:vec[i]){
			t[j]++;
		}
	}
	for(int i=0;i<=31;i++){
		if(t[i]>=m){
			st[i]=true;
		}
	}
	int sum=n;
	bool flag[200005];
	for(int i=0;i<2e5+3;i++)	flag[i]=true;
	long long ans=(1LL<<31)-1;
	for(int i=30;i>=0;i--){
		if(st[i]){
			for(int j=1;j<=n;j++){
				if(!flag[j]){
					continue;
				}
				//cout<<"999999999"<<endl;
				auto it=lower_bound(vec[j].rbegin(),vec[j].rend(),i);
				//it--;cout<<*it<<"-----"<<endl;
				if(*vec[j].begin()<i||*it!=i){
					sum--;flag[j]=false;
					if(sum==m){
						for(int k=1;k<=n;k++){
							if(flag[k]){
								ans&=a[k];
								//cout<<a[k]<<endl;
							}
						}
						break;
					}
					
				}
			}
			if(ans!=(1LL<<31)-1){
				cout<<ans<<endl;
				break;
			}
		}	
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	while(T--)	solve();
	return 0;
}

