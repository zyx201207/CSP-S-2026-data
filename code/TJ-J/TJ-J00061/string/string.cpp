#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum;
long long a,a1;
char b;
char l[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i =0 ;i<n;i++){
		cin>>a>>b;
		for(int j = a1;j<a1+a;j++){
			l[j] = b; 
		}
		a1+=a;	
	}
//	for(int i=0;i<a1;i++){
//		cout<<l[i]<<' ';
//	}
//	cout<<endl;
	int mid;
	if(a1 %2  == 0){
		mid = a1/2-1;
	} 
	if(a1 %2  == 1){
		mid = (a1+1)/2-2;
	} 
//	for(int i = 0;i<=mid;i++){
//		cout<<l[a1-i-1]<<' ';
//	}
//	cout<<endl;
//	for(int i = 0;i<=mid;i++){
//		cout<<l[i]<<' ';
//	}
	for(int i = 0;i<=mid;i++){
		if(l[i]!=l[a1-i-1]){
			sum+=1;
//			cout<<l[i]<<' '<<l[a1-i-1];
		}
	}
	cout<<sum;
	
	return 0;
}



