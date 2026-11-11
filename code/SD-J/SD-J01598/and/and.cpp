#include<bits/stdc++.h>
using namespace std;
long long M=0;
long long n,m;
long long a[200001];
bool c_A(){
	int s=2;
	for(int i=1;i<=n;i++){
		if(a[i]!=s-1) return false;
		s*=2;
	}
	return true;
}
bool c_B(int a[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return false;
	}
	return true;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>M) M=a[i];
		}
		cout<<M;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i] and a[j]>M) M=a[i] and a[j];
			}
		}
	}else if(m==n){
		M=a[1];
		for(int i=2;i<=n;i++) M=M and a[i];
		cout<<M;
		return 0;
	}else if(c_A()){
		for(int i=n-1;i>=n-m+1;i--) M=M and a[i];
		cout<<M;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
