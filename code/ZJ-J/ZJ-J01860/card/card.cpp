#include<bits/stdc++.h>
using namespace std;
const int M=300005,N=500005;
int n,m,a[N],tong[M];
int flag[M];
int head=1,tail,q[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				tail++;
				flag[a[j]]=tail;
				q[tail]=a[j];
			}
			else{
				while(tail>=flag[a[j]]){
					q[tail]=0;
					tail--;
				}
				tail++;
				flag[a[j]]=tail;
				q[tail]=a[j];
			}
		}
		while(head<=tail){
			tong[q[head]]++;
			head++;
		}
		head=1;
		tail=0;
		memset(q,0,sizeof(q));
		memset(flag,0,sizeof(flag));
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
