# include <bits/stdc++.h>
using namespace std;
map<int,int> M;
map<int,int> Q;
int A[100100],C[100100],Book[100100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		C[i]=M[A[i]];
		M[A[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++) Book[j]=1; 
		for(int j=i;j<=n;j++){
			if(C[j]!=0){
				if(Book[C[j]]!=0&&C[j]>=i){
					for(int k=C[j];k<j;k++) Book[k]=0;
				} 
			}
		}
		for(int j=i;j<=n;j++) if(Book[j]!=0) Q[A[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<Q[i]<<' ';
	return 0;
} 
