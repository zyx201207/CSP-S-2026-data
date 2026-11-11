#include<bits/stdc++.h>
using namespace std;
int c,t,sum;
int n,d;
int a[2000005];
int s(int x,int y){
	queue<int>q;
	queue<int>qd;
	q.push(x);
	qd.push(0);
	while(!q.empty()){
		int nx=q.front(),nd=qd.front();
		if(nx==y){
			break;
		}
		q.pop();
		qd.pop();
		for(int i=nx;i<=n;i++){
			if(d>=a[i]-a[nx]){
				q.push(i);
				qd.push(nd+1); 
			}
		}
	}
	int in=qd.front(),cnt=0;
	while(!qd.empty()){
		if(in==qd.front()){
			if(q.front()==y){
				cnt++;
			}
		}else{
			break;
		}
		qd.pop();
		q.pop();
	}
	if(cnt==2){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				sum+=s(j,i);
			}
		}
		cout<<sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
