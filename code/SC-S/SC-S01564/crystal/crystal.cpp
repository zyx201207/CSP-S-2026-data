#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> sj;
vector<long long> s;




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long tmp;
		cin>>tmp;
		sj.push_back(tmp);
	}
	sort(sj.begin(),sj.end());
	//求前缀和
	s.push_back(sj[0]);
	for(long long i=1;i<n;i++){
		s.push_back(s[i-1]+sj[i]);
	}
//	for(auto ed:s){
//		cout<<ed<<' ';
//	}
	long long max_=0;
	for(long long i=0;i<n;i++){
//		cout<<"在第"<<i+1<<"个水晶开启需要"<<((i*sj[i])-(s[i]-sj[i]))<<"能量"<<endl;
		if(((i*sj[i])-(s[i]-sj[i]))<=m){
			max_=i;
		}else{
			break;
		}
	}
	//O(nlogn)复杂度
	cout<<max_+1;
}