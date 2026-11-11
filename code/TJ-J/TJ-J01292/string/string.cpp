#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long i=0,j,n1,cnt=0,T,k,l;
struct{
	int n;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(i=0;i<T;i++){
		cin>>a[i].n>>a[i].c;
//		cout<<a[i].n;
	}
	i=0;
	n1=T;
//	cout<<a[1].n;
//	for(i=0;i<T-1;i++){
//		if(a[i].c==a[i+1].c){
//			a[i+1].n+=a[i].n;
//			a[i].n=0;
//		}
//	}
	while(i<T){
//		cout<<a[n1-1-i].n;
		if(a[i].n==0){
			i++;
//			cout<<5;
		}
		if(a[i].c==a[i+1].c){
			a[i+1].n+=a[i].n;
			a[i].n=0;
			i++;
			continue; 
		}
		k=0;
		while(i==i){
			if(n1-k-i<=i){
				cout<<cnt;
				return 0;
			}
//			if(a[n1-k-i].c==a[n1-k-i-1].c){
//				a[n1-k-i-1].n+=a[n1-k-i].n;
//				a[n1-k-i].n=0;
//				k++;
//				continue; 
//			}
			if(a[n1-k-i].n!=0){
				if(a[i].c!=a[n1-k-i].c){
					cnt+=min(a[i].n,a[n1-k-i].n);
//					cout<<2;
				}
				int x=a[i].n,y=a[n1-k-i].n;
				a[i].n-=min(x,y);
				a[n1-k-i].n-=min(x,y);
//				cout<<3;
				break;
			}else{
				k++;
			}
//			if(k>=n1-i){
//				cout<<cnt;
////				cout<<i<<a[n1-i-k].n;
//				return 0;
//			}
		}
		if(a[i+1].n==0){
			cout<<cnt;
			return 0;
		}
//		cout<<1;
	}
	cout<<cnt;
	return 0;
}
