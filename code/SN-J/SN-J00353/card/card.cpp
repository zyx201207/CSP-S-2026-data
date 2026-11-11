#include<bits/stdc++.h>
using namespace std;
struct a{
	long long data,id;
}l[30030];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[50050],b[30030];
	for(long long i=0;i<n;i++)cin>>a[i];
	for(long long i=0;i<m;i++){
		for(long long j=0;j<n;j++){
			if(a[j]==i+1){
				b[i]++;
			}
		}
	}
	b[a[n-1]-1]=n;
	for(long long i=0;i<m;i++){
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
