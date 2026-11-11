#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt[5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			bool flag1=0;
			bool flag2=0;
			
				if(a[n]==1)flag1=true;
				if(a[n]==2)flag2=true;
			
			if(flag1)cnt[1]++;
			if(flag2)cnt[2]++;
		}
	}
	
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
