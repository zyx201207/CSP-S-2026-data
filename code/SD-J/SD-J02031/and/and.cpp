#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	map<int,vector<int> > a;
	vector<int> b;
	int mabi=-1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		b.push_back(x);
		
		
	}
//	sort(b.begin(),b.end());
	for(int i=0;i<b.size();i++){
		int x=b[i];
		int tmp=x;
		while(tmp!=0){
//			cout<<111;
			a[tmp&-tmp].push_back(i);
			if(tmp==(tmp&-tmp)){
				mabi=max(tmp,mabi);
			}
			tmp-=tmp&-tmp;
		}
	}
//	cout<<mabi;
	vector<int>ans;
	for(int i=mabi;i>0;i/=2){
		if(a[i].size()<m){
			continue;
		}
		if(ans.size()==0){
			for(auto t:a[i]){
				ans.push_back(t);
			}
		}
		else if(ans.size()>m){
			int flag=0;
			vector<int>tmp;
			for(auto t:ans){
				if(*lower_bound(a[i].begin(),a[i].end(),t)==t){
					flag++;
					tmp.push_back(t);
				}
				
			}
			if(flag>=m){
				ans=tmp;
			}
		}
		else{
			break;
		}
	}
	int en=LLONG_MAX;
	for(auto t:ans) {
		en&=b[t];
	}cout<<en;
	return 0;
}
