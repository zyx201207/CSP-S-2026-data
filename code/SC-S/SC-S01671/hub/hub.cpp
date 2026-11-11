#include<bits/stdc++.h>
using namespace std;
const int maxa=2e5+10;
int c,t;
int n,k;
int head[maxa];
int k=0;
struct Edge{
	int to,next;
}e[maxa];
int k=0;
void adde(int x,int y){
	e[++k].to=y;
	e[k].next=head[x];
	head[x]=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(	;t>0;t--){
		//int x,y;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			adde(x,y);
		}
		cout<<"n-1"<<endl;
	} 
	return 0;
}