#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],t[32];
long long mo(int l){
//	for(int j=0;j<=30;j++) cout<<t[j]<<" ";
//	cout<<endl;
	for(int i=l;i>=0;i--){
		if(t[i]>m){
			long long mod=pow(2,i+1),k=pow(2,i);
			for(int j=1;j<=n;j++){
				if(a[j]%mod<k) a[j]=0;
			}
			for(int j=0;j<=30;j++) t[j]=0;
			for(int j=1;j<=n;j++){
				long long mid=a[j];
				for(int p=0;mid!=0;p++){
					t[p]+=mid%2;
					mid/=2;
				}
			}
//			cout<<"k:"<<k<<endl;
			return mo(i-1)+k;
		}else if(t[i]==m){
			long long mod=pow(2,i+1),k=pow(2,i),sum=pow(2,l+1)-1;
			for(int j=1;j<=n;j++){
				if(a[j]%mod>=k) sum&=a[j];
			}
//			cout<<"sum:"<<sum<<endl;
			return sum;
		}
	}
	return 0;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long mid=a[i];
		for(int j=0;mid!=0;j++){
			t[j]+=mid%2;
			mid/=2;
		}
	}
	cout<<mo(29);
	return 0;
} 
