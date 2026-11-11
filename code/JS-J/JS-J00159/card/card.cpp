#include <bits/stdc++.h>
#define maxn 563599
using namespace std;
int n,m;
int a[maxn];
int ans[maxn];
bool flag[maxn];
bool ss[maxn];
ifstream fin("card.in");
ofstream fout("card.out");
void solve(int i){
	vector<int> v(n+1);
	int pos[maxn];
	int ii=0;
	memset(flag,false,sizeof(flag));
	for(int j=i;j<=n;j++){
		if(flag[a[j]]){
			ii--;
			for(;ii>=pos[a[j]];ii--){
				flag[v[ii]]=false;
				v.pop_back();
			}
			ii++;
			flag[a[j]]=true;
			pos[a[j]]=ii;
		}
		else{
			v.push_back(a[j]);
			pos[a[j]]=ii;
			ii++;
			flag[a[j]]=true;
		}
	}
	for(auto e:v) ans[e]++;
}
int main(){
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
		ss[a[i]]=true;
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		if(ss[i]) fout<<ans[i]<<" ";
	}
	fout<<endl;
}