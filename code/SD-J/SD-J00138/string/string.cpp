#include<bits/stdc++.h>
using namespace std;
long long n,i[200005],ent=0;
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long j=1;j<=n;j++){
		cin>>i[j]>>a[j];
	}
	int q=1,p=n;
	while(q!=p){
		
		if(i[q]>=i[p]){
			if(a[q]!=a[p]){
				ent+=i[p];
			}
			i[q]-=i[p];
			p--;
			
		}else if(i[q]<i[p]){
			if(a[q]!=a[p]){
				ent+=i[q];	
			}
			i[p]-=i[q];
			q++;
			
		}
	}
	cout<<ent;
	return 0;
}
