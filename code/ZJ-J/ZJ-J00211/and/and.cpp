#include<bits/stdc++.h>
using namespace std;
long long a[200001][31],poi[200001],pui[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxp=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long k,p=0;
		cin>>k;
		pui[i]=k;
		while(k!=0){
			a[i][p]=k%2;
			k/=2;p++;
		}
		poi[i]=p-1;
		if(maxp<poi[i])maxp=poi[i];
	}
	vector<int>final;
	for(int i=1;i<=n;i++){
		final.push_back(i);
	}
	for(int i=maxp;i>=1;i--){
		vector<int>wf;
		for(int j=0;j<final.size();j++){
			int f=final[j];
			if(a[f][i]==1)wf.push_back(f);
		}
		if(wf.size()>=m&&wf.size()<final.size()){
			for(int j=0;j<final.size();j++)final.pop_back();
			for(int j=0;j<wf.size();j++)final.push_back(wf[j]);
		}
	}
	long long t=pow(2,63)-1;
	for(int i=0;i<final.size();i++){
		t|=pui[final[i]];
	}
	cout<<t;
	return 0;
}
