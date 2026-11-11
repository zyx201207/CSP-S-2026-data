#include<bits/stdc++.h>
using namespace std;
long long a[500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long clas=n/2;
	for(int i=1;i<=n;i++){
		if(clas-a[i]>0 && m>clas-a[i]){
			long long q=clas-a[i];
			m=m-q;
			a[i]=clas;
		}
		if(clas-a[i]>m||m<=0){
			break;
		}
	}	
	long long count=1;
	for(long long i=1;i<=n;i++){
		if(a[i]==clas){
			count++;
		}
	}
	cout<<count;
	
	return 0;
}

