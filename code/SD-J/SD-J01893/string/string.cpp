#include<bits/stdc++.h>
using namespace std;
long long c=0,s[200005],n,n1,g=0,q,q2,j=1,j2=0;
char z[200005],a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	n1=n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>z[i];
	}
	while(n1!=0){
		q=s[j];
		q2=s[n-j2];
		a=z[j];
		b=z[n-j2];
		if(q>=q2){
			q=q-q2;
			if(a!=b){
				c=c+q2;
			}	
			j2++;
		}else{
			q2=q2-q;
			if(a!=b){
				c=c+q;
			}
			j++;
		}
		n1--;
	}
	cout<<c;
	return 0; 
}
