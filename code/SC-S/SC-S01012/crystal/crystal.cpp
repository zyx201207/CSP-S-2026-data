#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//输入
	int n,m;
	cin>>m>>n;
	int a[65535];
	int cz[65535];
	int cz1[65535];
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
	//计算差 
	for(int o=1;o<=n;o++){
		if(a[j]>=a[o]){
			cz[o]=a[j]-a[o];
		}
		else{
			cz[o]=655355;
		}
		cz1[o]=cz[o];
	}
	//从小到大排序 
	for(int p=1;p<=n;p++){
		for(int j=p+1;j<=n;j++){
			if(cz1[j]<=cz1[p]){
			cz1[j]=cz1[p];
		}	
	}
	}
	
	//计算ans1,本次ans2 
	int ans1=0;
	int ans2=0;
	for(int q=1;q<=n;q++){
		if(ans1+cz1[q]<=m){
			ans1+=cz1[q];
			ans2++;
		}
		else{
			break;
		}
	}
	if(ans<=ans2){
		ans=ans2;
	}	
	}
	cout<<ans+1;
	return 0;
}