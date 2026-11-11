#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool f[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>sta;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				sta.push(a[j]);
			}else{
				while(sta.top()!=a[j]){
					f[sta.top()]=0;
					sta.pop();
				}
			}
			f[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			cnt[j]+=f[j];
			f[j]=0;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<cnt[j]<<" ";
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
