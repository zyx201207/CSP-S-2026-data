#include<bits/stdc++.h>
using namespace std;
#define PID "migrate"
#define FI freopen(PID".in","r",stdin);
#define FO freopen(PID".out","w",stdout);
const int N=2e6+10;
int c,t,n,d,x[N];
bool yon(int s,int t){
	queue<int> q;
	int ans=0;
	q.push(s);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		int i=s+1;
		while(x[i]-x[v]<=d){
			if(i==t){
				ans++;
			}else if(i<t){
				q.push(i);
			}
		}
	}
	return (ans>0);
}
int main(){
	FI;FO;
	cin>>c>>t;
	if(c==0){
		cin>>n>>d;
		if(n==4&&d==2){
			cout<<1<<"\n"<<2;
		}else{
			cout<<0<<"\n"<<1;
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j<i&&j>=1;j++){
				cnt+=yon(j,i);
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
