#include<bits/stdc++.h>
using namespace std;
int n,ans,i,j,k,midd;
long long a[500010],b,m,cnt;
int cellll(int a,int c){
	int z=a+c;
	if(z%2==0){
		return z/2;
	}
	else  return z/2+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=n;i>1;i--){
		a[i]=a[i]-a[i-1];
		//cout<<a[i]<<" ";
	}
	for(i=2,j=2,cnt=0,ans=1;j<=n;){
		//56cout<<12345;
		while(cnt<=m&&j<=n){
			j++; 
			midd=cellll(i,j);
			for(k=midd;k<=j;k++){
				cnt+=a[k];
				//cout<<cnt<<" ";
			}
		}
		ans=max(ans,j-i+1);
		while(cnt>m){
			i++;
			midd=(i+j)/2;
			for(k=i;k<=midd;k++){
				cnt-=a[k];
			}
		}
		
	}
	cout<<ans;
	return 0;
}
