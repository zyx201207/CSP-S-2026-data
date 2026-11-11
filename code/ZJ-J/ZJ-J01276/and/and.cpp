#include<bits/stdc++.h>
using namespace std;
int n,m,t,z=1,l1,l2,d=0,e;
bool cmd(int m,int n){
	if(m>=n) return 1;
	else return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n],s[m],b=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmd);
	for(int i=0;i<m;i++){
		t=a[i];
		s[i]=0;
		z=1;
		if(i==0)e=d;
		else if(e<d) e=d;
		d=0;
		while(t){
			if(t%2==1) s[i]+=t%2*z;
			z=z*10;
			t=t/2;
			d++;
		}
	}
	z=1;
	l2=s[1];l1=s[0];
	for(int i=0;i<m-1;i++){
		if(i!=0){
			l1=b;
			l2=s[i+1];	
		}
		z=1;
		b=0;
		for(int i=0;i<e;i++){
			if(l1%10==1&&l2%10==1) b=b+z;
			z=z*10;
			l1=l1/10;
			l2=l2/10;
		}
	}z=1;e=0;
	
	while(b){
		e=e+b%10*z;
		z=z*2;
		b=b/10;
	}
	cout<<e;
	return 0;
}
