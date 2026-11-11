#include<bits/stdc++.h>
using namespace std;
int n;//max=2e5
vector<pair<long long,char>>v;//max=1e9
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;//max=1e9
		char c;
		cin>>a>>c;
		v.push_back(make_pair(a,c));
	}
	int len=v.size();//max=2e5
	long long sum=0;//max=1e14
	int l=0;//max=2e5
	int r=len-1;//max=2e5
	while(l<len&&r>=0){
		if(v[l].first>v[r].first){
			v[l].first-=v[r].first;
			if(v[l].second!=v[r].second)sum+=v[r].first;
			v[r].first=0;
			r--;
		}else if(v[l].first<v[r].first){
			v[r].first-=v[l].first;
			if(v[l].second!=v[r].second)sum+=v[l].first;
			v[l].first=0;
			l++;
		}else{//v[l].first==v[r].first
			if(v[l].second!=v[r].second)sum+=v[l].first;
			v[l].first=v[r].first=0;
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}