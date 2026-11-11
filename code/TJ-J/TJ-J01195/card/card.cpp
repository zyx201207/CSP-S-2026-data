#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		stack<int> s;
		for(int j=0;j<m;j++){
			b[i]=0;
		}
		for(int j=i;j<n;j++){
			if(b[a[j]]==0) b[a[j]]++,s.push(a[j]);
			else{
				int g;
				for(auto t:s){
					if(a[j]==t){
						while(a[j]!=t){
							b[s.top]--;
							s.pop();
						}
					}
				}
			}
		}
		while(!s.empty()){
			c[s.top()]++;
			s.pop();
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
