#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long f[500005];
//vector<int> v[100005];
/*int toufen(int w){
	int h=0;
	int i=1;
	while(h<=w){
		h+=i;
		i++;
	}
	return i;
}*/
/*int jisuan(int i,vector<int> a){
	sort(a+i,a+a.size()-1);
	int h=0;
	while(h<m){
		h+=a[i];
		i++;
	}
	if(h==m){
		return i+1;
	}else if(){
		
	}
}*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int hh=1;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(f[i]!=i){
			hh=0;
		}
		/*for(int j=1;j<=m;j++){
			f[j][i]=f[0][i]+j;
		}*/
	}
	if(hh==1){
		int h=0;
		int i=0;
		while(h<=m){
			i++;
			h+=i;
		}
		cout<<i;
		//return 0;
	}
	/*for(int j=0;j<=m;j++){
		for(int i=1;i<=n;i++){
			v[f[i][j]].push_back(j);
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=v[i].size();j++){
			ans=max(ans,jisuan(0,v[i]));
		}
	}*/
	
	return 0;
}
