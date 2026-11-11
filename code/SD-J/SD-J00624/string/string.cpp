#include<bits/stdc++.h>
using namespace std;
int n,L,R;
long long A[200000+10],ans,T[200000+10];
char C[200000+10],C2[200000+10];
void inout(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
int main(){
	inout();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		cin>>C[i];	
	}
	int j=1;
	T[1]=A[1],C2[1]=C[1];
	for(int i=2;i<=n;i++){
		if(C[i]==C2[j])T[j]+=A[i];
		else{
			j++;
			T[j]=A[i];
			C2[j]=C[i]; 
		}
	}
	long long num=0;
	bool r=0,f=0;
	L=1,R=n;
	while(L<=R){
		if(C2[L]==C2[R]){
			if(T[L]>T[R])T[L]-=T[R],R--;
			else if(T[L]<T[R])T[r]-=T[L],L++;
			else L++,R--;
		}
		else {
			if(T[L]>T[R])T[L]-=T[R],ans+=T[R],R--;
			else if(T[L]<T[R])T[r]-=T[L],ans+=T[L],L++;
			else L++,R--,ans+=T[R];
		}
	}
	cout<<ans;
	return 0;
} 







