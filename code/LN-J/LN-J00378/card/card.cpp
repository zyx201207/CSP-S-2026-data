#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
vector<int> v;
unordered_map<int,bool> mp;
unordered_map<int,int> amp;
int ans[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    clock_t st=clock();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool xza=true;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) xza=false;
		if(xza) amp[a[i]]++;
	}
	if(xza){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i-1]==a[i]) continue;
			sum+=amp[a[i]];
			cout<<sum<<' ';
		}
		return 0;
	}
	v.reserve(N);
    for(int i=1;i<=n;i++){
		v.clear();
		mp.clear();
		for(int j=i;j<=n;j++){
			if(!mp[a[j]]) v.push_back(a[j]);
			else while(v.back()!=a[j]){
				mp[v.back()]=0;
				v.pop_back();
			}
			mp[a[j]]=1;
			if(double(clock()-st)/CLOCKS_PER_SEC>0.85) break;
		}
		if(double(clock()-st)/CLOCKS_PER_SEC>0.85) break;
		for(auto e:v) ans[e]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	//cerr<<endl;
	//clock_t end=clock();
	//double sec=double(end-st)/CLOCKS_PER_SEC;
	//if(sec>=1) cerr<<"TLE "<<sec<<endl;
	//else cerr<<"AC"<<endl;
    return 0;
}
