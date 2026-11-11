//¡ı∆Ù∞≤ SN-J00811 π§¥ÛA2 
#include <bits/stdc++.h>
using namespace std;
long long m,n,a[100001],a1,t[100001];
void ca(int i){
	bool f=1,b[100001];
	for(int j=i;j<n;j++){
		for(int p=0;p<n;p++){
			if(a[j]==b[p]){
				f=0;
			}
		} 
		if(f==1){
			int m=0;
			while(b[m]==0){
				m++;
			}
			b[m]=a[i];
		}else{
			int p=0;
			while(b[0]==a[j]){
				b[p]=b[p+1];p++;
			}b[p]=b[p+1];
		}
	}
	for(int j=0;j++;j<n-i){
	 	t[b[j]-1]++;			
	}
}
int main(){
	freopen("and.in","r",stdin);
	scanf("%ld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	for(int q=0;q<n;q++){
		ca(q);
	}
	for(int i=0;i<n;i++){
		printf("%ld",t[i]);
	}
	freopen("and.out","w",stdout);
}
