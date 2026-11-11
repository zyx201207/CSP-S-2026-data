#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m,a[10005];
int main(){
	freopen("kard.in","r",stdin);
	freopen("kard.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool flag=false;
		for(int j=1;j<i;j++){
			if(a[i]==a[j]){
				flag=true;
			}
		} 
		if(flag){
			while(s.top()!=a[i]&&!s.empty()){
				s.pop();
			}
		}
		else{
			s.push(a[i]);
		}
		int ans=0;
		stack<int> ss=s;
		while(!s.empty()){
			if(s.top()==i){
				ans++;
			}
			s.pop();
		}
		cout<<ans<<" ";
	}
	return 0;
} 

