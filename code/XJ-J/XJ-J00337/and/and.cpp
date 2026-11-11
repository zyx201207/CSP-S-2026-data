#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[1000005],c[100005],s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>s){
			s=a[i];
		}
	}
	if(m=1){
		cout<<s;
	}else if(m=n){
		int k=1,kk;
		while(a[1]>0){
			b[k]=a[1]%2;
			a[1]=a[1]/2;
		}
		for(int i=2;i<n;i++){
			for(int i=1;i<=10005;i++){
				c[i]=0;
			}
			kk=1;
			while(a[i]>0){
				c[k]=a[i]%2;
				a[i]=a[i]/2;
			}
			for(i=1;i<=max(k,kk);i++){
				if(b[i]==1 && c[i]==1){
					b[i]=1;
				}else{
					b[i];
				}
			}
		}
		int i=1,d=1;
		s=0;
		while(d<max(k,kk)){
				s+=b[d]*i;
				d++;
				i*=2;
		}
	}else{
		cout<<a[2];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}