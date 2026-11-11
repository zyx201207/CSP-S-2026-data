#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
bool check[300005];
int mem[300005];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	 
	memset(ans,0,sizeof(ans));
	memset(check,false,sizeof(check));
	memset(mem,0,sizeof(mem));
	cin>>n;
	int t=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(t--){
		memset(mem,-1,sizeof(mem));
		memset(check,false,sizeof(check));
		for(int i=n-t;i<n;i++){
			if(check[a[i]]==true){
				int t=mem[a[i]];
				for(int j=t;j<=i;i++){
					mem[a[j]]=0;
					check[a[j]]=false;
				}
			}
			else{
				mem[a[i]]=i;
				check[a[i]]=true;
			}
		}
		for(int i=0;i<m;i++){
			if(check[i]==true){
				ans[i]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
