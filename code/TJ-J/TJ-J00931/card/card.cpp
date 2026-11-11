#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M];
int st[2*N],h;
int whr[M];

void gm(int xx){
	memset(whr,0,sizeof(whr));
	memset(st,0,sizeof(st));
	h=0;
	
	for(int i=xx;i<=n;i++){
		if(whr[a[i]]!=0){
			while(st[h]!=a[i]){
				whr[st[h]]=0;
				h--;
			}
		}
		else{
			st[++h]=a[i];
			whr[a[i]]=h;
		}
		//for(int i=1;i<=h;i++) cout<<st[i]<<' ';
		//cout<<'\n';
	}
	for(int i=1;i<=h;i++) ans[st[i]]++;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		gm(i);
		//cout<<'\n';
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
