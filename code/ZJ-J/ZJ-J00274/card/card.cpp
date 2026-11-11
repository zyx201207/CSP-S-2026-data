#include<bits/stdc++.h>
#include<vector>
using namespace std;

int n,m,r=1;
int a[1000010];
int ans[500010];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(r<=n){
		for(int i=r;i<=n;i++){
			bool f=0;
			for(auto j:v){
				if(j==a[i]) f=1;
			}
			if(f==1){
				while(true){
					if(v.back()!=a[i])v.pop_back();
					else if(v.back()==a[i]){
						v.pop_back();
						break;
					}
				}
			}
			v.push_back(a[i]);
		}
		for(auto i:v){
			ans[i]++;
		}
		v.clear();
		r++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

