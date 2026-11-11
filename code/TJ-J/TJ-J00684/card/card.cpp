#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+3,M=3e5+3;
long long n,m;
long long a[N],b[N];
struct node{
	long long id;
	bool f;	
}t[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long j=1;j<=m;j++){
		for(long long i=j-1;i<n;i++){
			if(t[a[i]].f==0){
			b[i]=a[i];
			t[a[i]].f=1;
			t[a[i]].id=i;
			}else{
				for(long long k=t[a[i]].id;k<=i+1;k++){
					b[k]=0;
	    			}
			}
		}
		int cnt=0;
		for(long long i=0;i<n;i++){
			if(b[i]==j) cnt++;
		}
		cout<<cnt<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
