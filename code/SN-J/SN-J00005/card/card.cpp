#include <bits/stdc++.h> 
using namespace std;
int A[500005],B[500005];
int chcon(int a,int b){
	for(int i=1;i<b;i++){
		if(A[i]==a){
			return 1;
		}
	}
}
int cg(int ll,int rr){
	for(int i=ll;i<=rr;i++){
		B[A[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}  

	for(int i=1;i<=n;i++){
		int l=0,r=0;
		for(int j=i;j<=n;j++){
			r++;
			if(chcon(A[r],r)==1){
				l=r;
			}
			
		}
		cg(l,r);
		cout<<l<<" "<<r<<endl;
		
	}
	for(int i=0;i<n;i++){
		if(B[i]!=0){
			cout<<B[i]<<" ";
		}
	}  
	return 0;
}
