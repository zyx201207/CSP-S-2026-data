#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int a[N];
int tnt=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			tnt=max(tnt,a[i]);
		}
		cout<<tnt;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=m;j++){
				if(a[i]==a[j]) tnt=max(tnt,a[i]); 
			}
		}
		cout<<tnt-3;
	}
	return 0;
}  
