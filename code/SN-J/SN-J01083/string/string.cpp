#include<bits/stdc++.h>
using namespace std;
long long n;
long long cd=0;
char hw[1000000006];
int aa=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			long long s=cd+j;
			hw[s]=b;
		}
		cd+=a;
	}
//	cout<<cd;
//	int aaa;
//	hw.size(aaa);
//	cout<<aaa;
//	for(int i=1;i<=cd;i++){
//		cout<<i;
//		cout<<hw[i];
//	}
	if(cd%2==0){
		long long cd2=cd/2;
		for(long long i=1;i<=cd2;i++){
			long long ss=cd-i;
			ss+=1;
			if(hw[i]!=hw[ss]){
				aa++;
			}
		}
	}
	else{
//	cout<<1;
		long long cd2=cd-1;
		cd2=cd/2;
//		cout<<cd2;
		for(long long i=1;i<=cd2;i++){
			long long ss=cd-i;
			ss+=1;
//			cout<<ss<<endl;
			if(hw[i]!=hw[ss]){
				aa++;
			}
		}
	}
	cout<<aa;
	return 0;
}
