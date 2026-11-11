#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0; i<n; ++i){
		cin>>a[i];
		--a[i];
	}
	
	int c[n],ans[m];
	for(int i=0; i<m; ++i) ans[i]=0;
	for(int i=0; i<n; ++i){            //¾Ö 
		int k=0;                       //ÅÆ¶ÑÅÆ 
		while(c[k]!=-1&&k<n){
			c[k]=-1;
			++k;
		}
		for(int j=i; j<n; ++j){        //ÊÖÅÆ 
			bool flag=false;
			k=0; 
			while(c[k]!=-1&&k<n){
				if(c[k]==a[j]){
					flag=true;
					break;
				}
				++k;
			}
			if(flag){
				++k;
				while(c[k]!=-1&&k<n){
					c[k]=-1;
					++k;
				}
			}else c[k]=a[j];
		}
		k=0;
		while(c[k]!=-1&&k<n){
			++ans[c[k]];
			++k;
		}
	}

	for(int i=0; i<m; ++i) cout<<ans[i]<<' ';
	
	return 0;
}

