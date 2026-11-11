#include<bits/stdc++.h>
using namespace std;
int q[5010],y;
int n,m,a[5010];
int c[3010];int b[30010]={};
void aaa(int x){
	b[30010]={};
	for(int i=x;i<=n;i++){
		b[a[i]]++;
		if(b[a[i]]==0){
			q[y]=a[i];y++;
		}else{
			while(1){
				y--;b[q[y]]--;
				if(q[y]==a[i]){
					break;
				}
				q[y]=0;
			}
		}
	}
	for(int i=1;i<=y;i++){
		c[q[i]]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	y=1;
	for(int i=1;i<=n;i++){
		aaa(i);
	}
	for(int i=1;i<=m;i++){
		cout<<c[i];
	}
	return 0;
}
