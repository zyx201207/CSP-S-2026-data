#include<bits/stdc++.h>
using namespace std;
bool f=1;
int n,m,l;
long long ans=-1;
long long a[200005];
vector<long long> v1,v2;
void dfs(int id,int sum,long long num){
	//cout<<id<<" "<<sum<<" "<<num;
	bool f=0;
	if(sum==0) f=1;
	if(num<=ans&&f==0) return;
	if(sum>=m){
		ans=num;
		return;
	}
	if(id>int(v1.size())) return;
	//cout<<"sss"<<v2[id]<<"sss"<<endl;
	if(f){
		//cout<<'A'<<" ";
		dfs(id+1,v2[id],v1[id]);
		//cout<<'B'<<" ";
		dfs(id+1,0,0);	
	}
	else{
		//cout<<"C"<<" ";
		dfs(id+1,sum+v2[id],(num&v1[id]));
		//cout<<'D'<<" "; 
		dfs(id+1,sum,num);	
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f){
			bool ff=0;
			long long ss=1;
			if(a[i]==0){
				continue;
			}
			for(int j=1;j<=20;j++){
				ss*=2;
				if(a[i]==ss-1) ff=1;
			}
			if(ff==0) f=0;
		}
		
	} 
	sort(a+1,a+1+n,greater<long long>());
	if(f){
		cout<<a[m];
		return 0;
	}
	int t=a[1],cnd=1;
	for(int i=2;i<=n;i++){
		if(t!=a[i]){
			v1.push_back(t);
			v2.push_back(cnd);
			//cout<<t<<" "<<cnd<<" ";
			cnd=1;
			t=a[i];
		}
		else cnd++;
	}
	v1.push_back(t);
	v2.push_back(cnd);
	dfs(0,0,0);
	if(ans==-1) cout<<0;
	else cout<<ans;
	return 0;
}
