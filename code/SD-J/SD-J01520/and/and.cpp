#include<bits/stdc++.h>
using namespace std;
int a[200003];
bool vis[200003],op[200004];;
int w[40],ans=0;
int sp(int i){
	int js=1;
	for(int j=1;j<=i;j++)
		js=js*2;
	return js;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int i=30;i>=0;i--){
		int js=0,s=sp(i);
		for(int j=0;j<=n;j++)
			op[j]=0;
			
		for(int j=1;j<=n;j++)
			if(vis[j]==0){
				if(a[j]>=s)
					js++;
				else
					op[j]=1;
			}
			
		if(js>=m){
			w[i]=1;
			for(int j=1;j<=n;j++)
				if(op[j]==1)
					vis[j]=1;
		}
		
		for(int j=1;j<=n;j++)
			if(op[j]==0)
				a[j]=a[j]-s;
	}
	
	for(int i=0;i<=30;i++){
		if(w[i]==1)
			ans=ans+sp(i);
	}
	cout<<ans;
}
