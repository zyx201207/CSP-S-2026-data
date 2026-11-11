#include<bits/stdc++.h>
using namespace std;

long long A[500010];
long long B[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long h;
	int t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	sort(A+1,A+n+1);
	h=A[2]-A[1];
	for(int i=2;i<=n;i++){
		if(A[i]-A[i-1]!=h){
			t=-1;
			break;
		}
	}
	if(t==0){
		for(int i=1;i<=n;i++){
			if(m-(h*i)<=0){
				cout<<i;
				return 0;
			}
			m-=(h*i);
		}
		cout<<n;
		return 0;
	}
	else{
		int zuixiao=0;
		for(int i=2;i<=n;i++){
			for(int kai=1;kai<n;kai++){
				int zhi=0;
				for(int j=kai;j<=i;j++){
					zhi+=(A[i]-A[j]);
				}
				if(zhi<=m){
					zuixiao=max(zuixiao,i-kai+1);
				}
			}
		}
		cout<<zuixiao;
		return 0 ;
		
	}
	return 0;
}
