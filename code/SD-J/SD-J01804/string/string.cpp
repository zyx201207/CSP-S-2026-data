#include<bits/stdc++.h>
using namespace std;
long long n,A[200100],i,j,ans,t,s,u;
char C[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>A[i]>>C[i];
	}
	i=1;j=n;
	t=A[1];
	s=A[n];
	while(i<=j){
		if(C[i]==C[j]){
			u=min(s,t);
			t-=u;
			s-=u;
			if(t==0){
				i++;
				t=A[i];
			}
			else{
				j--;
				s=A[j];
			}
		}
		else{
			u=min(s,t);
			ans+=u;
			t-=u;
			s-=u;
			if(t==0){
				i++;
				t=A[i];
			}
			else{
				j--;
				s=A[j];
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
