#include<bits/stdc++.h>
using namespace std;
long long vis[100005][35],n,m,a,cnt,f,ans;
set<long long> s,ss,sss;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=1;j<=30;j++){
			vis[i][j]=a&1;
			a=a>>1;
		}
	}
	for(int i=30;i>=1;i++){
		for(int j=1;j<=n;j++){
			if(vis[j][i]==1)ss.insert(j);
		}
		if(ss.size()>=m){
			for(auto it:s)sss.insert(it);
			for(auto it:ss)sss.insert(it);
			if(sss.size()!=ss.size()){
				if(f==0){
					for(auto it:s)s.erase(it);
					for(auto it:ss)s.insert(it);
				}
				else {
					long long l=0;
					for(auto it:ss)if(sss.find(it)!=sss.end())l++;
					l=sss.size()-l;
					if(s.size()-l>=m){
						for(auto it:sss)if(ss.find(it)==ss.end())s.erase(s.find(it));
					}
				}
			}
			f=1;
		}
		for(auto it:ss)ss.erase(it);
	}
	for(auto it:s){
		if(ans==0)ans=it;
		ans=ans&it;
	}
	cout<<ans;
}