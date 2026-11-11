#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
stack<int> s,s3;
map<int,int> s2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=m;i++) cout<<n<<' ';
		return 0;
	}
	if()
	for(int i=n;i>=1;i--){
		s.push(a[i]);
		s2[a[i]]+=1;
		if(s2[a[i]]==2){
			s.pop();
			s2[a[i]]=1;
			while(s.top()!=a[i]){
				s2[s.top()]=0;
				s.pop();
			}
		}
		int l=s.size();
		for(int j=1;j<=l;j++){
			b[s.top()]++;
			cout<<s.top()<<' ';
			s3.push(s.top());
			s.pop();
		}
		cout<<endl;
		for(int j=1;j<=l;j++){
			s.push(s3.top());
			s3.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
