#include <bits/stdc++.h>
using namespace std ;
int n,m,a[500005] ;
set <int> st ;
map <int,int> mp ;
bool xz1 = true ;
//xz1:–‘÷ a 
void f1(){
	for(int i=1;i<=n;i++){
		int b[500005] ;
		memset(b,0,sizeof(b)) ;
		b[i] = a[i] ;
		for(int j=i+1;j<=n;j++){
			if(a[j]!=a[j-1]){
				b[j] = a[j] ;
			}
		}
		for(int j=i;j<=n;j++){
			mp[b[j]] ++ ;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
}
void f2(){
	f1() ;
} 
int main(){
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i] ;
		if(a[i-1]>a[i]) xz1 = false ;
	}
	if(xz1){
		f1() ;
	}
	else{
		f2() ;
	}
	return 0 ;
} 
