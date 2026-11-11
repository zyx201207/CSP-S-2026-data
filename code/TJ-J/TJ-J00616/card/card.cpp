#include<bits/stdc++.h>
using namespace std;
int b[300005],z[500005],cnt;
int n,m;
queue<int> q,p;
int find_pos(int k){
	for(int i=0;i<n;i++){
		if(z[i]==k) return i;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		q.push(a);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int frt=q.front();
			p.push(frt);
			q.pop();
			int pos=find_pos(frt);
			if(pos==-1) z[cnt++]=frt;
			else{
				for(int k=pos;k<n;k++) z[k]=0;
				z[pos]=frt;
			}
			for(int x=0;x<n;x++){
				if(z[x]!=0){
					b[z[x]]++;
				}
			}    
			swap(q,p);
			for(int y=0;y<n;y++){
				z[y]=0;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
