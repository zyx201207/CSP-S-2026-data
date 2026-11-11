#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	int mi=0,q=0;
	for(int k=0;k<n-1;k++){
		mi+=b[k]*(k+1);
	}
	for(int i=1;i<n;i++){
		int p=0;
		int l=i-1;
		int r=i;
		int j=n-1-i;
		int t=i;
		while(l>=0||r<=n-1-i){
				if(l<0&&r<=n-2){
					p+=b[r]*j;
				}else if(l>=0&&r>n-1-i){
					p+=b[l]*t;
				}else{
					p+=b[r]*j+b[l]*t;
				}
				l--;r++;j--,t--;
		}
		if(p<mi){
			mi=p;
			q=i;
		}
	}
	for(int i=0;i<n;i++){
		c[i]=abs(a[i]-a[q]);
	}
	sort(c,c+n-1);
	int h=0;
	while(m>0){
		m-=c[h];
		h++;
	}
	if(m<0){
		h-=1;
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
