#include <bits/stdc++.h>
using namespace std;
int a[200010];
vector<int>b[30];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		for(int j=0;j<30;j++){
			if((a[i]&(1<<j))!=0){
				b[j].push_back(a[i]);
			}
		}
	}
	int ans=0;
	for(int i=29;i>=0;i--){
		if(b[i].size()>=m){	
			ans=b[i][0];
			for(int j=1;j<m;j++){
				ans&=b[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}

           
           