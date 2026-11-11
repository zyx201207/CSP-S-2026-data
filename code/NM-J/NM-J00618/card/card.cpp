#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20001]={0};
	int b[20001]={0};
	int cnt[20001]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	queue<int>c;
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(b[a[i]]==1){
				c.push(a[i]);
				cnt[a[i]]--;
				
			}else{
				b[a[i]]=1;
				c.push(a[i]);		
		}	
	}
		while(!c.empty()){
			cnt[c.front()]++;
			b[c.front()]=0;
			c.pop();
		}
}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
