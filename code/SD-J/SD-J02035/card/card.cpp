#include<bits/stdc++.h>
using namespace std;
	int n,m,a[500005],lta[300005],dta[300005],cf[500005],sl[300005];
int ind(){
	int gs=0,fs=1;
	char cg=getchar();
	while(cg<'0'||cg>'9'){
		if(cg=='-'){
			fs=-1;
		}
		cg=getchar();
	}
	while(cg>='0'&&cg<='9'){
		gs=gs*10+(cg-'0');
		cg=getchar();
	}
	return gs*fs;
}
void outd(int od){
	if(od<10){
		putchar('0'+od);
		return ;
	}
	else{
		outd(od/10);
		putchar('0'+(od%10));
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		lta[i]=-1;
	}
	for(int i=1;i<=n;i++){
		a[i]=ind();
		lta[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dta[a[i]]=lta[a[i]];
	}
	int k;
	for(int i=n;i>=1;i--){
		k=dta[a[i]];
		while(k<n){
			cf[k]++;
			k=dta[a[k+1]];
		}
	}
	cf[n]=n;
	for(int i=1;i<=n;i++){
		sl[a[i]]=max(sl[a[i]],cf[i]);
	}
	for(int i=1;i<=m;i++){
		outd(sl[i]);
		putchar(' ');
	}
	
	
	
	
	
	
	
	
	
	return 0;
} 

