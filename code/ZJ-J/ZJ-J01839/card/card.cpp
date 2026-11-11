#include<bits/stdc++.h>
using namespace std;
int cjj_a[500005],cjj_b[300005],cjj_c[500005];
set<int>cjj[300005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int cjj_n,cjj_m;
	cin>>cjj_n>>cjj_m;
	for(int i=1;i<=cjj_n;i++){
		cjj_b[i]=-1;
		cjj_c[i]=-1;
	}
	for(int i=1;i<=cjj_n;i++){
		cin>>cjj_a[i];
	}
	for(int i=1;i<=cjj_n;i++){
		if(cjj_b[cjj_a[i]]!=-1){
			cjj_c[i]=cjj_b[cjj_a[i]];
		}
		cjj_b[cjj_a[i]]=i;
	}
	vector<int> chenchenkx;
	int cnt=0;
	for(int i=cjj_n;i>=1;i--){
		for(int j=cnt;j<=i;j++){
			cjj[cjj_a[i]].insert(j);
		}
		if(cjj_c[i]!=-1){
			chenchenkx.push_back(cjj_c[i]);
		}
		while((cnt>=i||cnt==0)&&i!=1&&!chenchenkx.empty()){
			sort(chenchenkx.begin(),chenchenkx.end(),cmp);
			cnt=chenchenkx.front();
			chenchenkx[0]=0;
		}
	}
	for(int i=1;i<=cjj_m;i++){
		cout<<cjj[i].size()-1<<" ";
	}
	return 0;
}

