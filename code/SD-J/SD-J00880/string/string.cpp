#include<bits/stdc++.h>
using namespace std;
long long n,a,mid,lens,ans,cnt;
char c;
vector<pair<long long,char>> v,vf,vb;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;lens+=a;
		if(!v.empty()&&v.back().second==c)v.back().first+=a;
		else v.push_back({a,c});
	}
	n=v.size();
	mid=lens/2;
	for(int i=0;i<n;i++){
		cnt+=v[i].first;
		if(cnt>mid){
			vf.push_back({v[i].first-(cnt-mid),v[i].second});
			if(lens&1)cnt--;
			for(int j=n-1;j>i;j--){
				vb.push_back({v[j].first,v[j].second});
			}
			if(cnt-mid)vb.push_back({cnt-mid,v[i].second});
			break;
		}else if(cnt==mid){
			vf.push_back({v[i].first,v[i].second});
			if(i+1<n&&(lens&1))v[i+1].first--;
			for(int j=n-1;j>i;j--){
				vb.push_back({v[j].first,v[j].second});
			}
			break;
		}else vf.push_back({v[i].first,v[i].second});
	}
	long long it=0,ib=0;
	while(it<vf.size()&&ib<vb.size()){
		if(vf[it].first==vb[ib].first){
			if(vf[it].second!=vb[ib].second)ans+=vf[it].first;
			it++;ib++;
		}else if(vf[it].first<vb[ib].first){
			if(vf[it].second!=vb[ib].second)ans+=vf[it].first;
			vb[ib].first-=vf[it].first;it++;
		}else{
			if(vf[it].second!=vb[ib].second)ans+=vb[ib].first;
			vf[it].first-=vb[ib].first;ib++;
		}
	}
	cout<<ans;
	return 0;
} 
