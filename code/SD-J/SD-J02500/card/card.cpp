#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500010],flag=1,b[500010],step[500010],now,ans[300010];
bool check[300010];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i+1])flag=0;
		b[i]=b[i-1]+a[i];
	}
	
	if(flag==0){
		for(int i=1;i<=n;i++){
			cout<<b[i]<<' ';
		}
		
		return 0;
	}
	
	for(int t=1;t<=n;t++){
		now=0;
		memset(check,0,sizeof check);
		memset(step,0,sizeof step);//2 3 1 2 1
		
		for(int i=t;i<=n;i++){
			if(step[a[i]]){
				now=step[a[i]];
				
			}
			else {
				now++;
				b[now]=a[i];
				step[a[i]]=now;
			}
		}
		
//		for(int i=1;i<=now;i++){
//			cout<<b[i]<<' ';
//		}
		
		for(int i=1;i<=now;i++){
			if(check[b[i]])continue;
			
			check[b[i]]=1;
			ans[b[i]]++;
//			cout<<b[i]<<' ';
		}
//		cout<<endl;
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}

	return 0;
}

