#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],t,mt,t2,ans;
bool v[200005][31];
vector<int>ve[31];
map<int,int>ma;
void f(){
	for(int i=mt;i>=0;i--){
		vector<int>v2[31];
		if(ve[i].size()>=m){
			for(int j:ve[i]){
				for(int k=0;k<=30;k++){
					if(v[j][k])v2[k].push_back(j);
				}
			}
			for(int j=0;j<=30;j++)ve[j]=v2[j];
		}
	}
	for(int i=0;i<=30;i++){
		if(ve[i].size()>=m){
			ans=a[ve[i][0]];
			for(int j=1;j<m;j++)ans&=a[ve[i][j]];
			return;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++)ma[(1<<i)]=i;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=a[i];
		while(t){
			t2=ma[(t&(-t))];
			mt=max(mt,t2);
			v[i][t2]=1;
			ve[t2].push_back(i);
			t-=(t&(-t));
		}
	}
	f();
	cout<<ans;
	return 0;
}
