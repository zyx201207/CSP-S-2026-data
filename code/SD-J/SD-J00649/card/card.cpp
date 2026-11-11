#include<bits/stdc++.h>
using namespace std;
int a[500005];
stack<int>s;
int ans[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!s.empty()){
			s.pop();
		}
		for(int j=i;j<=n;j++){
			bool f=0;
			for(int k=s.size();k>=1;k--){
				if(s.top==a[j]){
					f=1;
					int cnt=s.size()-k;
					while(cnt--){
						s.pop();
					}
				}
			}
			if(f==0){
				s.push(a[j]);
			}
		}
		
		
	}
	return 0;
}

