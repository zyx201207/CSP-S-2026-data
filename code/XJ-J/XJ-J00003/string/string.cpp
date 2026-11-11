#include "bits/stdc++.h"
using namespace std;
//
//struct Str{
//	string z[1005],f[1005];
//	int id[20005];
//};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a;
	string l;
	char b;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		sum+=a/2;
	}
	if(n==1){
		cout<<0;
		return 0;
	}else{cout<<sum;
	}
//	cout<<l<<endl;
//	int mid=0;
//	if(sum%2==0){
//		mid=sum/2;
//	}else{
//		mid=sum/2+1;
//	}
//	for(int i=1;i<=mid;i++){
//		for(int j=mid;j>=1;j--){
//			str.z[i]=l[i];
//			str.id[i]=j;
//		}
//	}
//	for(int i=mid;i<=l.size();i++){
//		for(int j=1;j<=mid;j++){
//			str.f[i]=l[i];
//			str.id[i]=j;
//		}
//	}
//	cout<<l<<endl<<str.z<<endl<<str.f<<endl;
//	for(int i=1;i<=l.size();i++){
//		cout<<str.id[i]<<' ';
//	}
}