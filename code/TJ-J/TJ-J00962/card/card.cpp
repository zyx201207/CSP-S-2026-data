#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans1=0,ans2=0;
void play1(int n,int j,vector<int> &v){
	int head=v[j],len=1;
	pair<int,int> ans;
	for(int i=j+1;i<n;i++){
		if(len==1){
			if(v[i]!=head) len++;
		}else{
			if(v[i]==head) len=1;
		}
	}
	if(len==2){
		ans1++;
		ans2++;
	}else if(head==1){
		ans1++;
	}else{
		ans2++;
	}
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	if(m==1){
		cout<<n;
	}else if(m==2){
		for(int i=0;i<n;i++){
			play1(n,i,v);
		}
		cout<<ans1<<" "<<ans2;
	}else{
		vector<int> ans(m,1);
		for(int j=1;j<n;j++){
			if(v[j]==v[j-1]) ans[v[j]-1]++;
		}
		cout<<ans[0];
		for(int j=1;j<m;j++){
			ans[j]+=ans[j-1];
			cout<<" "<<ans[j];
		}
	}
	return 0;
}
