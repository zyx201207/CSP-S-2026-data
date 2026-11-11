#include<bits/stdc++.h>
using namespace std;
int n,m,f;
int a[500005],anss[500005];
vector<int> cu;
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f=1;
			if(cu.empty()) {cu.push_back(a[j]);continue;}
			for(long unsigned int k=0;k<cu.size();k++){
				if(cu[k]==a[j]){
					int num=cu.size()-k+1;
					while(num){cu.pop_back();num--;}
					f=0;break;
				}
			}
			if(f) cu.push_back(a[j]);
		}
		for(long unsigned int k=1;k<=cu.size();k++) anss[cu[k]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int k=1;k<=n;k++) scanf("%d",&a[k]);
	solve();
	for(int i=1;i<=m;i++) cout<<anss[i]<<" "; 
	return 0;
}
