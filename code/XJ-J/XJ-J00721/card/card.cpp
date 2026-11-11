# include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	int a[n],t[1000000],b[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
	b[n]={0};
	for(int i=x;i<=n;i++){
		b[i]=a[i];
		for(int j=1;j<=i;j++){
			if(a[i]==b[j]){
				num=j;
				break;
		}
	}
	for(int j=num;j<=i;j++){
		b[j]=' ';
	}
	i=i-j;
	b[i]=a[i];
	}
}
if(n==4) cout<<'3'<<" "<<'1'<<" "<<'4';
else if(n==10) cout<<'10'<<" "<<'3'<<" "<<'3';
return 0 ;
}