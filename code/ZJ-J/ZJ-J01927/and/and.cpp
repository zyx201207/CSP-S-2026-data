#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt[40],a[200005],ans,mx;
vector<int>v[40];
vector<int>v2[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>a[i];
		x=a[i];
		int j=0;
		while(x){
			cnt[++j]+=x%2;
			if(x%2){
				v[j].push_back(a[i]);
			}
			x/=2;
		}
	}
	mx=0;
	for(int i=35;i>=1;i--){
		if(cnt[i]>=m){
			mx=i;
			break;
		}
	}
	ans+=(1<<(mx-1));
	for(int i=1;i<40;i++){
		cnt[i]=0;
	}
	int f=1;
	
	
	
	
	while(mx){
		for(int i=1;i<=39;i++){
			cnt[i]=0;
		}
		if(f){
			for(int i=0;i<v[mx].size();i++){
				int x=v[mx][i];
				int j=0;
				while(x!=0){
					cnt[++j]+=x%2;
					if(x%2){
						v2[j].push_back(v[mx][i]);
					}
					x=x/2;
				}
			}
			for(int i=0;i<40;i++)v[i].clear();
		}else{
			for(int i=0;i<v2[mx].size();i++){
				int x=v2[mx][i];
				int j=0;
				while(x!=0){
					cnt[++j]+=x%2;
					if(x%2){
						v[j].push_back(v2[mx][i]);
					}
					x=x/2;
				}
			}
			for(int i=0;i<40;i++)v2[i].clear();
		}
		cnt[mx]=0;
		mx=0;
		for(int i=35;i>0;i--){
			if(cnt[i]>=m){
				mx=i;
				break;
			}
		}
		if(mx>0)ans+=(1<<(mx-1));
		
	}
	cout<<ans;
	return 0;
}
