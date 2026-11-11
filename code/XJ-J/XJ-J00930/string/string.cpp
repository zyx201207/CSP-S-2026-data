#include<bits/stdc++.h>
using namespace std;
int a,n=0,mid,sum=0,d,e,f,g=0,h=2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	char c[a];
	int m[a];

	for(int i=0;i<a;i++){
//		cin>>m;

		cin>>m[i]>>c[i];
		sum+=i;
	}
		char l[sum/2],r[sum/2];
	
	if(sum%2==0){
	
		d=0;
	}
	else{
		char l[(sum-1)/2],mid,r[(sum-1)/2];
		d=1;	
	}
			
	
//	for(int j=0;j<a;j++){
//		if(d==0){
//			if(sum<=a/2){
//				cin>>l[i+sum];
//				sum++;
//			}
//			else{
//				cin>>r[i+sum];
//				sum++;
//			}
//		}
//	}
	for(int j=0;j<a;j++){
		for(int i=0;i<m[j];i++){
			if(d==0){
				if(n<=sum/2){
					l[n]=c[j];
					n++;
				}
				else{
					r[n]=c[j];
					n++;
				}
			}
			else{
				if(n<=(sum-1)/2){
					l[n]=c[j];
					n++;
				}
				else if(n==(sum-1)/2+1){
					mid=c[j];
					n++;
				}
				else{
					r[n]=c[j];
					n++;
				}
			}
		}
	}
	
	for(int i=0;i<sum/2;i++){
		if(l[i]!=r[sum/2-i]){
			while(1){
				if(f>=sum/2-f)
				break;
				if(l[i]==r[sum/2-f]){
					g=r[sum/2-i];
					r[sum/2-i]=r[sum/2-f];
					r[sum/2-f]=g;
					h++;
				}
				f++;
			}
			while(1){
				if(f<=sum/2)
				break;
				if(l[i]==l[f]){
					g=r[sum/2-i];
					r[sum/2-i]=l[f];
					l[f]=g;
					h++;
				}
				f++;
			}
		}
	}
	if(c[1]==c[sum-1]){
		cout<<0;
	}
	else{
		cout<<h;
	}
	return 0;
	
}











