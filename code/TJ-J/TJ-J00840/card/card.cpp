#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
bool f=1;
int n,m,a[maxn],ans[maxn]={};
vector<int>jh;
bool check(int x){
	int ss=jh.size();
	for(int i=0;i<ss;i++){
		if(jh[i]==x)return 0;
	}
	return 1;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		jh.clear();
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(check(a[j])){
				cnt++;
				jh.push_back(a[j]);
			}else{
				int idx=1,b[1005]={};
				for(int k=0;k<cnt;k++){
					if(jh[k]==a[j]){
						break;
					}else{
						b[idx++]=jh[k];
					}
				}
				idx--;
				jh.clear();
				for(int k=1;k<=idx;k++){
					jh.push_back(b[k]);
				}
				cnt=jh.size()+1;
				jh.push_back(a[j]);
			}
		}
		for(int i=0;i<cnt;i++){
			ans[jh[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
