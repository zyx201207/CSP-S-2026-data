#include<bits/stdc++.h>
using namespace std;
char l[1000000000000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cn=0;
	long long cnt=0;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a;
		cin>>b;
		for(long long j=cn;j<cn+a;j++){
			l[j]=b;	
			
		}
		cn=cn+a;
	}
	if(cn%2==0){
		long long s2=cn/2;
		for(long long i=s2;i<cn;i++){
			if(l[i]!=l[s2-1-(i-s2)]){
				cnt++;
			}
		}
	}else{
		long long s2=cn/2;
		for(long long i=s2;i<cn;i++){
			if(l[i]!=l[s2-(i-s2)]){
				cnt++;
			}
		}
			
	}
	cout<<cnt;


	return 0;
}
