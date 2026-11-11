#include<bits/stdc++.h>
using namespace std;
typedef long long llt;
	int n;
	llt a[500005],m,d,maxn,sj;
llt ind(){
	llt g=0,f=1;
	char cg=getchar();
	while(cg<'0'||cg>'9'){
		if(cg=='-'){
			f=-1;
		}
		cg=getchar();
	}
	while(cg>='0'&&cg<='9'){
		g=g*10+(cg-'0');
		cg=getchar();
	}
	return f*g;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=ind();
	}
	sort(a+1,a+n+1);
	maxn=-1;
	llt j=0;
	for(llt i=1;i<=n;i++){
		if(i==1){
			j=i;
			sj=0;
			while(sj<=m&&j<n){
				sj+=(a[j+1]-a[j])*(j-i+1);
				if(sj>m){
					sj-=(a[j+1]-a[j])*(j-i+1);
					break;
				}
				j++;
			}
			maxn=max(maxn,j);
		} 
		else{
			sj-=a[j]-a[i-1];
			while(sj<=m&&j<n){
				sj+=(a[j+1]-a[j])*(j-i+1);
				if(sj>m){
					sj-=(a[j+1]-a[j])*(j-i+1);
					break;
				}
				j++;
			}
			maxn=max(maxn,(j-i+1));
		}
	}
	cout<<maxn;
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
