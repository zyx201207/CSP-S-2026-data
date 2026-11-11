#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],dq,my,ans[300005];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}

	for(int q=dq;q<=n;q++){
		for(int i=0;i<=n;i++){
	b[i]=a[i];
	}
	for(int i=dq;i<=n;i++){
		for(int j=dq;j<=n;j++){
			if(a[i]==a[j]){
				for(int k=i;k<=j;k++){
					b[k]=0;	
					my=k;
				}
					i=my+1;
					j=my+1;
			}
		}
	}
	for(int i=0;i<=n;i++){
		if(b[i]!=0){
			ans[i]++;
		}
	}
	dq++;
}
for(int i=0;i<=m;i++){
cout<<ans[i];
}

	return 0;
}
