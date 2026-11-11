#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m;
int a[500007],pre[500007],ans[500007];
bool added[500007];
int now[500007]; 
void ch(int st,int fl){
	memset(now,0,sizeof(now));
	memset(added,0,sizeof(added));
	memset(pre,0,sizeof(pre));
	int idx=0;
	for(int i=st;i<=fl;i++){
		int u=a[i];
		if(pre[u]==0){
			idx++;
			pre[u]=idx;
			now[idx]=u;
		}
		else{
			for(int j=pre[u]+1;j<=idx;j++){
				pre[now[j]]=0;
				
			}
			idx=pre[u];
			
		}
	} 
	for(int i=1;i<=idx;i++){
		if(added[now[i]])continue;
		added[now[i]]=1;
		//if(now[i]==3)cout<<st<<endl;
		ans[now[i]]++;
	}
}
signed main(){
	//那我模拟了呗 
	freopen("card.in" , "r" , stdin);
	freopen("card.out" ,"w" , stdout);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool A1=1;
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1])A1=0;
	} 
	if(A1==1){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
		return 0;
	}
	for(int i=1;i<=n;i++){
		ch(i,n);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
} 
