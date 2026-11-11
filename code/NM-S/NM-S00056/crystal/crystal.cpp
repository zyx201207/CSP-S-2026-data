#include<bits/stdc++.h>
using namespace std;
long long n,m,a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long>v1;
	vector<long long>v2;
	for(long long i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	sort(v1.begin(),v1.end());
	int len=v1.size();
	for(long long i=0;i<len-1;i++){
		v2.push_back((v1[i+1]-v1[i])*(i+1));
	}
	int cl=0,ans=1,len1=v2.size();
	for(long long i=0;i<len1;i++){
		cl+=v2[i];
		if(cl>m){
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
