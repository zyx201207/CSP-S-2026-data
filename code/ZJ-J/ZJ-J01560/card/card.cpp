#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[300010],q[500010],b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		q[++t]=b[i];
		for(int j=1;j<t;j++){
			if(q[j]==b[i]){
				t=j;
				break;
			}
		}
	}
	for(int i=1;i<=t;i++){
		a[q[i]]++;
	}
	for(int k=2;k<=n;k++){
		t=0;
		memset(q,0,sizeof(q));
		for(int i=k;i<=n;i++){
			q[++t]=b[i];
			for(int j=1;j<t;j++){
				if(q[j]==b[i]){
					t=j;
					break;
				}
			}
		}
		for(int i=1;i<=t;i++)a[q[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

