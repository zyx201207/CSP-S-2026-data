#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,a[200005],ans;
bool vis[200005];
string to_2(int x){
	string r1;
	while(x>1){
		char r=x%2+'0';
		r1=r+r1;
		x/=2;
		//cout<<"r1:"<<r1<<" r:"<<r<<endl;
	}
	char r=x%2+'0';
	r1=r+r1;
	return r1;
}
int to_10(string x){
	int r=0,m=1;
	for(int i=x.size()-1;i>=0;i--){
		r+=(x[i]-'0')*m;
		m*=2;
	}
	return r;
}

string MAX(string a,string b){
	if(a.size()!=b.size()){
		if(a.size()>b.size()){
			return a;
		}
		else return b;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]>=b[i])return a;
	}
	return b;
}

string AND(string a,string b){
	int n=max(a.size(),b.size());
	int st=n-min(a.size(),b.size());
	string r;
	int j=0;
	if(a.size()>b.size()){
		for(int i=st;i<n;i++,j++){
			if(a[i]=='1'&&b[j]=='1')r+='1';
			else r+='0';
		}
	}
	else{
		for(int i=st;i<n;i++,j++){
			if(a[j]=='1'&&b[i]=='1')r+='1';
			else r+='0';
		}
	}
	return r;
}

void dfs(int step,string cnt){
	if(step>m){
		ans=MAX(ans,cnt);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			cnt=AND(cnt,a[i]);
			vis[i]=false;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long t;
		cin>>t;
		a[i]=to_2(t);
	}
	dfs(0,"0");
	cout<<to_10(ans);
	/*string x1,x2;
	cin>>x1>>x2;
	cout<<AND(x1,x2);*/
	return 0;
}
