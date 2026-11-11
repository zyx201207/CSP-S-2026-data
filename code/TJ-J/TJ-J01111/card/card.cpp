#include<bits/stdc++.h>

using namespace std;
const int N=5e5+10,M=3e5+10;

int n,m;
int a[N];
int buc[M];
int x[N],ptr;
int ans[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)cout<<n;
	else if(m==2){
		for(int i=n;i>=1;i--){
			if(buc[a[i]]>0)while(x[ptr]!=a[i])buc[x[ptr]]--,ptr--;
			else buc[a[i]]++,x[++ptr]=a[i];
		 	for(int j=1;j<=m;j++)ans[j]+=buc[j];
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	else{
		for(int i=1;i<=n;i++){
			memset(x,0,sizeof x);
			memset(buc,0,sizeof buc);
			ptr=0;
			for(int j=i;j<=n;j++){
				if(buc[a[j]]>0)while(x[ptr]!=a[j])buc[x[ptr]]--,ptr--;
				else buc[a[j]]++,x[++ptr]=a[j];
			}
			for(int i=1;i<=m;i++)ans[i]+=buc[i];
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	return 0;
}
