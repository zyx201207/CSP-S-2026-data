#include<bits/stdc++.h>
using namespace std;
int sy[100000];//²ÎÓë 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,symax=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
	    if(i<m){
	    	if(p>symax){
			    symax=i;	
			}
			sy[i]=p;
		}else{
			int um=-1;
			for(int i=0;i<m;i++){
				if(p>sy[i]){
					um=i;
				}
			}if(um!=-1){
				sy[um]=p;
			}
			if(p>sy[symax]){
				symax=um;
			}
		}
	}
	int cnt=sy[0];
	for(int i=1;i<m;i++){
		cnt=cnt&sy[i];
	}
	cout<<cnt;
	return 0;
}
