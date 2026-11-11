#include<bits/stdc++.h>
using namespace std;
int id[3005];
int num[3005];
int a[5005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(id,0,sizeof(id));
		for(int j=i;j<=n;j++){
			if(id[a[j]]==0){
				s.push(a[j]);
				id[a[j]]=j;
			}
			else{
				//cout<<j<<"\n";
				while(s.top()!=a[j]){
					id[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			num[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
