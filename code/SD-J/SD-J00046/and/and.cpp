#include<bits/stdc++.h>
using namespace std;
int a[200005],ret[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	int cnt=0,num=0;
	while(maxn>>=1)cnt++;
	for(int i=(1<<cnt);i>=1;i>>=1){
		vector<int>ans;
		int s=0;
		for(int j=1;j<=n;j++){
			if(ret[j]==num){
				if((a[j]&i)!=0){
					s++;
					ans.push_back(j);
				}
			}
		}
		if(s>=m){
			for(int j=0;j<ans.size();j++)
				ret[ans[j]]++;
			num++;
		}
	}
	int sum=0;
	bool f=false;
	for(int i=1;i<=n;i++){
		if(ret[i]==num){
			if(f)sum=sum&a[i];
			else f=true,sum=a[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}
