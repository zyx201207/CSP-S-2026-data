#include <bits/stdc++.h>
using namespace std;
const int INT=2e5;
int n,m;
int a[INT],b[INT];
stack<int> s,s2;
bool find(int x){
	while(!s.empty()){
		if(s.top()==x){
			while(!s2.empty()){
				s.push(s2.top());
				s2.pop();
			}
			return true;	
		}
		else {
			s2.push(s.top());
			s.pop();
		}
	}
	while(!s2.empty()){
		s.push(s2.top());
		s2.pop();
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(find(a[j])){
				while(s.top()!=a[j]) s.pop();
				if(!s.empty()) s.pop();
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			b[s.top()]++;
			s.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
