#include <bits/stdc++.h>

using namespace std;

int n,m,ans[300005];
int a[500005];
int j[500005][20];

int hash[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	for(int i = 0;i <= n;i++){
		j[i][0] = i+1;
	}
	for(int i = 1;i <= n;i++){
		hash[a[i]] = i;
	}
	for(int i = 1;i <=n;i++){
		j[i][0] = hash[a[i]];
	}
	
	//cout<<endl;
	for(int k = 1;k < 20;k++){
		for(int i = 1;i <= n;i++){
			j[i][k] = j[j[i][k-1]][k-1];
			//cout<<j[i][k]<<" ";
		}
		//cout<<endl;
	}
	for(int t = 1;t <= n;t++){
		bool h[300005];
		memset(h,0,sizeof h);
		int i = t;
		if(t+1 == j[t][0]){
			//cout<<a[t]<<endl;
			ans[a[t]]++;
			h[a[t]] = 1;
		}
		while(i <= n){
			//cout<<i<<":"<<j[i][0]<<":";
			i = j[i][0];
			//cout<<t<<" "<<i<<" "; 
			if(!h[a[i]]){
				//cout<<a[i]<<endl;
				ans[a[i]]++;
				h[a[i]] = 1;
			}
			i++;
		}
		//cout<<"yo"<<endl;
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

