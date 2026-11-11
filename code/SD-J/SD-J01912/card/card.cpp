#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[100004],t,b[100006];
stack <int> q;
bool ind(int x,int y,int t){
	for(int i=0;i<=q.size()+1;i++){
		if(a[i]==x){
			return 0;
		}
	}
	return 1;
} 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=t;j<=n;j++){
			if(ind(a[j],j,t)){
				q.push(a[j]);
			}
		}
		for(int j=1;j<=n;j++){
			if(!q.empty()){
				b[q.top()]++;
				q.pop();
			}
		}
	}
	cout<<1;
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//毁灭吧，不想活了QWQ 我要创造一个没有次次夫的世界 

