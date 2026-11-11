#include<bits\stdc++.h>
using namespace std;
int n,m,z,a[300000],c,s1[1000000],_s1[1000000],s2[1000000],_s2[1000000],ans[1000000],_ans[1000000];

int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	sort(a+1,a+n+1);
	for(int i=n-1;n-i>m;i--){
		c=0,z=0;
		while(a[i]>0){
			c++;
			_s1[c]=a[i]%2;
			a[i]=a[i]/2;	
		}
		for(int j=1;j<=c;j++){
			s1[j]=_s1[c-j+1];
		}
	
		while(a[i]>0){
			z++;
			_s2[z]=a[i+1]%2;
			a[i+1]=a[i+1]/2;	
		}
		for(int j=1;j<=z;j++){
			s2[j]=_s2[z-j+1];
		}
		
		
		for(int j=max(z,c);j>=1;j--){
			if(s1[c])
			_ans[j]=1;
		}
	}
	cout<<a[n];
	return 0;
}
