#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],ans[100010];
bool inst[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<long long>sk; 
		for(int j=i;j<=n;j++){
			if(!inst[a[j]]){
				inst[a[j]]=1;
				sk.push(a[j]);
			}else{
				while(!sk.empty()&&sk.top()!=a[j]){
					inst[sk.top()]=0;
					sk.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(inst[j]){
				ans[j]++;
			}
			inst[j]=0;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
