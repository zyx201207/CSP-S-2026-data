#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,a[100001],max,l[100001]cnt,p,w[100001],q[100001]gf=0,k=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int z=0;z<m;z++){
		for(int i=0;i<n;i++){
			if(b[i]>max){
				max=b[i];
				p=i;
			}
		l[z]=max;
		max=0;
		b[i]=0;
		p=0;
		}
	}
	for(int i=0;i<m;i++){
		while(l[i]==0){
			int j=0;
			w[100001-i-i*m/10]=l[i]%2;
			l[i]/2;
			j++
		}
		if(w[100001-i-i*m/10])==1&&w[100001-i-i+1*m/10-1]==1)
			q[i]==1;
			gf++;
		}
	for(int i=0;i<gf;i++){
		k+=q[i]*2;
	}
	cout<<k;
	return 0;
}
