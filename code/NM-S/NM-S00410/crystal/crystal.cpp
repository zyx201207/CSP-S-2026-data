#include<bits/stdc++.h>
using namespace std;
int n,m,su=0,nn=0,j=1;
int a[10008];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		su+=a[i];
	}
	su/=n;
	while(m>0){
		m=m+a[su-j]-su;
		nn++;
		j++;
	}
	if(m<0){
		nn--;
	}
	cout<<nn;
	return 0;
} 

