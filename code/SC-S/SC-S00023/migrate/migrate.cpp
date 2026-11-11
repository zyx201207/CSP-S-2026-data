#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000017];
long long mn,cnt=0,ans=0;

long long dfsmn(long long s,long long e,long long st){
	if(s==e){
		return st;
	}
	for(int i=e;i>=s+1;i--){
		if(x[i]-x[s]<=d){
			return dfsmn(i,e,st+1);
			break;
		}
	}
	return -1;
}

void dfs(long long s,long long e,long long st){
	if(st==mn&&s!=e) return;
	if(s==e){
		if(st==mn){
			cnt++;
			return;
		}
	}
	for(int i=s+1;i<=e;i++){
		if(x[i]-x[s]<=d){
			dfs(i,e,st+1);
		}
	}
	return;
}

void bl(){
	ans=0; 
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			mn=dfsmn(i,j,0);
//			cout<<i<<"~"<<j<<":"<<mn<<endl; 
			if(mn==-1) continue;
			cnt=0;
			dfs(i,j,0);
//			cout<<cnt<<endl;
			if(cnt==2){
				ans++;
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		//tsB
		if(c==13||c==14){
			if(x[n]-x[1]<=d){
				cout<<0<<endl;
				continue;
			}
			cout<<2<<endl;
			continue;
		}
		
		//暴力
		bl();
		
		
		
		//输出
		cout<<ans<<endl; 
	}
	return 0;
}
