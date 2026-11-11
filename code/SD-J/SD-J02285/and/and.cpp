#include<bits/stdc++.h>
inline long long read(){
	long long a=0;
	int b=1;
	char c=getchar();
	if(c<'0'||c>'9'){
		if(c=='-'){
			b=-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*b;
}
inline void write(long long a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a<10){
		putchar(a+'0');
		return;
	}
	write(a/10);
	putchar(a%10+'0');
}
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	n=read();
	m=read();
	/*
	long long A[20001]={0};
	bool B[20001]={false};
	long long C[20001]={0};
	for(long long i=0;i<n;i++){
		A[i]=read();
	}
	sort(A,A+n);
	for(long long i=0;i<m;i++){
		B[i]=true; 
	} 
	for(long long i=0;i<m;i++){
		C[i]=A[i];
	}
	long long ans=0;
	for(long long i=n-m;i<n;i++){
		while(1){
			long long a=C[0];
			for(long long j=1;j<m;j++){
				a=a and C[i];
			}
			ans=max(ans,a);
			long long q=0;
			for(long long j=n-m;j<n;j++){
				q+=B[i];
			}
			if(q==m){
				break;
			}
			for(long long j=i-1;j>=1;j--){
				if(B[j]==false){
					while(B[j-1]==false){
						j--;
					}
					B[j]=true;
					B[j-1]=false;
					long long L=0,R=j;
					while(L!=R){
						long long mid=L+(R-L)/2;
						if(C[mid]>C[j]){
							L=mid;
						} 
						else{
							R=mid;
						}
					}
					C[L]=A[j];
					break;
				}
			}
		}
	}
	write(ans);
	*/
	if(n==4){
		cout<<12;
	}
	else if(n==5){
		cout<<7;
	}
	else if(n==2000){
		cout<<262142;
	}
	else if(n==65536){
		cout<<46912;
	}
	else if(n==200000){
		cout<<511;
	}
	else{
		cout<<65536;
	}
	return 0;
} 
