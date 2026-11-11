#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3000];
vector<int>b[3000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-m+1;i--){
		stack<int>k;
		while(a[i]){
			k.push(a[i]%2);
			a[i]/=2;
		}
		
		while(!k.empty()){
			b[n-i+1].push_back(k.top());
			k.pop();
		}
	}
	vector<int>k;
	for(int i=0;i<b[2].size();i++){
		k.push_back(b[2][i]);
	}
	for(int i=1;i<m;i++){
		
		if(b[i].size()>=k.size()){
			while(k.size()!=b[i].size()){
				k.push_back(0);
			}
			for(int j=0;j<b[i].size();j++){
				if(b[i][j]==k[j]){
					k[j]=1;
				}else{
					k[j]=0;
				}
			}
		}else{
			while(k.size()!=b[i].size()){
				b[i].push_back(0);
			}
			for(int j=0;j<b[i].size();j++){
				if(b[i][j]==k[j]){
					k[j]=1;
				}else{
					k[j]=0;
				}
			}
		}
		if(i==1){
			i+=1;
		}
	}
	int ans=k[k.size()-1];
	int l=1;
	for(int i=k.size()-2;i>=0;i--){
		for(int j=1;j<=k.size()-1-i;j++){
			l*=2;
		}
		l*=k[i];
		ans+=l;
		l=1;
	}
	cout<<ans;
	return 0;
}