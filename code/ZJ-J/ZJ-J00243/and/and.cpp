#include <bits/stdc++.h>
using namespace std;

string ttt(int a){
	string s="";
	stack<int> qq;
	while(!qq.empty())qq.pop();
	while(a){
		qq.push(a%2);
		a/=2;
	}
	while(!qq.empty()){
		s+=(qq.top()+'0');
		qq.pop();
	}return s;
}
int tt(string s){
	int ans=0;
	int l=s.length();l--;
	int r=0;
	while(l>=0){
		int ans2=1;
		for(int i=0;i<r;i++)ans2*=2;
		ans+=(s[l]-'0')*ans2;
		l--;r++;
	}return ans;
}
string awy(string a,string b){
	string c;
	stack<char> qp;
	while(!qp.empty())qp.pop();
	for(int i=max(a.length(),b.length())-1;i>=0;i--){
		if(a[i]==b[i]&&a[i]==1)qp.push('1');
		else qp.push('0');
	}
	while(!qp.empty()){
		c+=(qp.top());
		qp.pop();
	}
	return c;
}
bool cmp(int a,int b){
	if(a>b)return true;
	return false;
}
int a[200005];
queue<string>q; 
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	while(!q.empty())q.pop();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		q.push(ttt(a[i]));
	}
	if(m==1){
		int maxn=-1;
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
		}cout<<maxn;
	}
	else if(m==2){
		int maxn=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				string c=awy(ttt(a[i]),ttt(a[j]));
				maxn=max(maxn,tt(c));
			}
		}cout<<maxn;
	}
	else{
		sort(a,a+n,cmp);
		cout<<a[m-1]; 
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}//4 2
//3 15 12 12
