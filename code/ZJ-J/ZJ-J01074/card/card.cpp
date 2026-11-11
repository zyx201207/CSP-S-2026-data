#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],b[300010],last[300010],p[300010];
int n,m;
void play(int x){
	for(int i=1;i<=m;i++){
		last[i]=0;
		p[i]=0;
	}
	int top=0;
	for(int i=x;i<=n;i++){
		if(!last[a[i]]||last[a[i]]>top){
			p[++top]=a[i];
			last[a[i]]=top;
		}
		else{
			top=last[a[i]];
		}
	}
	for(int i=1;i<=top;i++){
		b[p[i]]++;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		play(i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
