#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s,h,d,f,q,c=0,max=0;
	cin>>n>>m;
	int a[n]={},b[n]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	} 
	for(int i=1;i<=n;i++){
		s=0;
		while(a[i]>0){
			s*=10;
			s+=a[i]%2;
			a[i]/=2;
		}
		a[i]=s;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				if(b[i]>max){
					max=b[i];
				}
				}else{
					s=a[i];
					h=a[j];
					c=0;
					while(s&&h){
						c++;
						f=s%10;
						q=h%10;
						if(f==1 && q==1){
							d+=1*c;
						}
						s/=10;
						h/=10;
					}
					c=0;
					s=0;
					while(d){
						s+=(d % 10)^c;
						d/=10;
						c++;
					}
					if(max<s){
						max=s;
					}
				}
		}
	}
	cout<<max;
	return 0;
}
