#include<bits/stdc++.h>
using namespace std;
int n,m;
int A[500000+10],C[300000+10],S[500000+10];
bool B[300000+10];
void inout(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
int main(){
	inout();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	if(m==1){
		cout<<(n+1)/2;
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++)cout<<n<<" ";
		return 0;
	}

	for(int j=1;j<=n;j++){
		memset(B,0,sizeof(B));
		int top=0;
		for(int i=j;i<=n;i++){
			if(B[A[i]]){
				while(S[top]!=A[i]){
					B[S[top]]=0;
					top--;
				}
				B[S[top]]=0,top--;
			}
			else B[A[i]]=1,S[++top]=A[i];
		}
		for(int i=1;i<=m;i++){
			if(B[i])C[i]++;
			
		}
	} 
	for(int i=1;i<=m;i++)cout<<C[i]<<" "; 
	return 0;
} 










