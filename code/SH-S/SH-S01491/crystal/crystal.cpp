#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
set<long long> a;
map<long long,int> ump;
vector<long long> v;
long long sum[N];
int num[N];
bool check(int x,int d){
	long long cnt=(num[d]-num[x-1])*v[d]-(sum[d]-sum[x-1]);
	if(cnt<=m)return true;
	return false;
}
int getout(int x,int d){
	int res=0;
	long long cnt=0,k;
	cnt=(num[d]-num[x])*v[d]-(sum[d]-sum[x]);
	
	if(cnt<=m){
		k=m-cnt;
		res+=num[d]-num[x]+k/(v[d]-v[x]);
	}
	return res;
}
int find(int id){
	int l=1,r=id-1,cnt=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,id)){
			r=mid-1;
			cnt=max(cnt,num[id]-num[mid-1]);
		}else{
			l=mid+1;
			cnt=max(getout(mid,id),cnt);
		}	
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.insert(x);
		ump[x]++;
	}
	int j=1,ans=0;
	v.push_back(-1);
	for(auto it=a.begin();it!=a.end();it++){
		v.push_back(*it);
		num[j]=ump[*it];
		sum[j]=ump[*it]*(*it);
		if(j){
			num[j]+=num[j-1];
			sum[j]+=sum[j-1];
		}
		//cout<<"总和 数量："<<sum[j]<<" "<<num[j]<<"\n";
		j++;
	}
	for(int i=1;i<v.size();i++){
		ans=max(ans,find(i));
	}
	cout<<ans;
	return 0;
} 
