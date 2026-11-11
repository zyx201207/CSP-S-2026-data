#include <bits/stdc++.h>
using namespace std;
int n; long long m,x,c,e,w;
vector<pair<long long,long long>> num;
//priority_queue<map<long long,long long>,vector<map<long long,long long> >,greater<map<long long> > > num;
multiset<long long> cnt;
vector<pair<long long,long long>> num2;
long long ans,ans2;
int main(){
	freopen("crystal.in","r",stdin);
	freout("crystal.out","w",stdout);
	cin>>n>>m;e=m;	
	for(int i=0;i<n;i++){
		cin>>x;
		cnt.insert(x);
		//cout<<lin.count(x)<<' '<<x<<endl;
	}
	for(int i=0;i<n;i++){
		auto y=*cnt.begin();
		if((long long)cnt.count(y)>=c){
			c=max(c,(long long)cnt.count(y));
			w=i;
		}
		num.push_back({cnt.count(y),y});
		num2.push_back({cnt.count(y),y});
		cnt.erase(y);
		if(cnt.size()==0) break;
	}
	
	/*
	for(int i=0;i<num.size();i++){
		cout<<num[i].first<<' '<<num[i].second<<endl;
	}*/
	
	long long t=n/2;
	for(int i=t;i>=0;i--){
		while(m-(num[t].second-num[i].second)>=0&&num[i].first>0){
			m-=(num[t].second-num[i].second);
		    ans++;
		    num[i].first--;
		    //cout<<m<<' '<<ans<<' '<<num[i].first<<' '<<num[i].second<<endl;
		}
		if(m<0) break;
	}
	//cout<<ans<<endl;
	t=w; 
	for(int i=t;i>=0;i--){
		while(e-(num2[t].second-num2[i].second)>=0&&num2[i].first>0){
			e-=(num2[t].second-num2[i].second);
		    ans2++;
		    num2[i].first--;
		    //cout<<m<<' '<<ans<<' '<<num[i].first<<' '<<num[i].second<<endl;
		}
		if(m<0) break;
	}
	cout<<max(ans,ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
