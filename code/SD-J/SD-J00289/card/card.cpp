#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[300010];
long long q[5000010],t=-1,f=0;
bool tong[300010]; 
void push(int _){q[++t]=_;}
void pop_back(){t--;}
long long front(){return q[f];}
long long size(){return t+1-f;}
bool empty(){return !size();}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(tong[a[i]])while(a[i]!=q[t])tong[q[t]]=0,pop_back();
		else push(a[i]),tong[a[i]]=1;
		for(int i=f;i<=t;i++)ans[q[i]]++;
		cerr<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<'\n';
		for(int i=f;i<=t;i++)cerr<<q[i]<<',';
		cerr<<'\n';
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
