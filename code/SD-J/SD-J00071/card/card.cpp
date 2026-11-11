#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
int flag[N];
long long cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof flag);
		vector<int> v;
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				v.push_back(a[j]);
				flag[a[j]]=1;
			}
			else{
				int idx=0;
				for(int k=0;k<v.size();k++){
					if(v[k]==a[j]){
						idx=k;
						break;
					} 
				}
				for(int k=idx;k<v.size();k++){
					flag[v[k]]=0;
				}
				if(!v.empty()) v.erase(v.begin()+idx+1);
				flag[a[idx]]=1;
			}
		}
		for(int k=0;k<v.size();k++){
			++cnt[v[k]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

