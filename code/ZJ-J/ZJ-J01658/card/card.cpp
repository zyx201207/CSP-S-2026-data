#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans[200005];
vector<int>now;
bool f=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		now.clear();
		for(int j=i;j<=n;j++){
			int flag=-1;
			for(int k=0;k<now.size();k++){
				if(now[k]==a[j]){
					flag=k;
					break;
				}
			}
			if(flag!=-1){
				for(int k=1;k<=now.size()-flag-1;k++){
					now.erase(now.begin()+flag+1);
				}
			}
			else{
				now.push_back(a[j]);
			}
		}
		for(int j=0;j<now.size();j++){
//			cout<<now[j]<<" ";
			ans[now[j]]++;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
