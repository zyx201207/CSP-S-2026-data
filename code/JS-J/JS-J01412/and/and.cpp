#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r,gs,jg,isend;
}a[1000005];
queue<long long> q;
queue<long long> qq;
long long cnt=1,dq=1,n,m,tmp,jd=1,ans,aans;
void pt(long long x){
	for(long long i=31;i>=0;i--){
		//if(x==12){
			//cout<<i<<' ';
		//}
		if(x/(pow(2,i))==1){
			if(a[dq].l==0){
				cnt++;
				a[dq].l=cnt;
			}
			a[a[dq].r].jg=a[dq].jg*2+1;
			dq=a[dq].l;
			a[dq].gs++;
			x-=(1<<i);
		}else{
			if(a[dq].r==0){
				cnt++;
				a[dq].r=cnt;
			}
			a[a[dq].r].jg=a[dq].jg*2;
			dq=a[dq].r;
			a[dq].gs++;
		}
		if(i==0){
			a[dq].isend=1;
		}
	}
	//cout<<'?';
}
void dfs(long long x){
	//cout<<'!'<<endl;
	if(a[x].l!=0&&a[a[x].l].gs!=0){
		dfs(a[x].l);
	}
	if(a[x].r!=0&&a[a[x].r].gs!=0){
		dfs(a[x].r);
	}
	if(a[x].isend==1){
		qq.push(a[x].jg);
	}
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		dq=1;
		pt(tmp);
		//cout<<'!';
	}
	//cout<<'?'<<endl;
	//for(int i=1;i<=32;i++){
		//long long gz,gy;
		//gz=a[jd].gs;
		//gy
	//}
	q.push(2);
	while(!q.empty()){
		long long dqjd=q.front();
		q.pop();
		if(a[a[dqjd].l].gs!=0){
			q.push(a[dqjd].l);
		}
		if(a[a[dqjd].r].gs!=0){
			q.push(a[dqjd].r);
		}
		//cout<<a[a[dqjd].l].gs<<' '<<a[a[dqjd].r].gs<<endl;
		if(a[a[dqjd].l].gs==m){
			ans=a[dqjd].l;
			break;
		}
		if(a[a[dqjd].r].gs==m){
			ans=a[dqjd].r;
		}
	}
	//cout<<ans;
	
	//cout<<'?'<<endl;
	dfs(ans);
	//cout<<'?'<<endl;
	aans=qq.front();
	//cout<<'?';
	
	qq.pop();
	while(!qq.empty()){
		aans=aans&qq.front();
		qq.pop();
	}
	cout<<aans;
	return 0;
}

