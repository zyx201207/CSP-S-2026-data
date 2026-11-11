#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans=0;
long long xa,xx;
char xc;
struct node1{
	long long a;
	char c;
}arr[200005];
struct node2{
	long long a;
	char c;
}brr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
		brr[n-i+1].a=arr[i].a;
		brr[n-i+1].c=arr[i].c;
	}
	for(int i=1;i<=(n+1)/2;i++){
		char ac=arr[i].c,bc=brr[i].c;
		long long aa=arr[i].a,ba=brr[i].a;
		if(i==1){
			if(ac!=bc){
				if(aa==ba){
					ans+=aa;
					xa=0;
				}else if(aa>ba){
					xx=1;
					xa=aa-ba;
					xc=ac;
					ans+=ba;
				}else{
					xx=2;
					xa=ba-aa;
					xc=bc;
					ans+=aa;
				}
			}else{
				if(aa==ba){
					xa=0;
				}else if(aa>ba){
					xx=1;
					xa=aa-ba;
					xc=ac;
				}else{
					xx=2;
					xa=ba-aa;
					xc=bc;
				}
			}
		}else{
			if(xa!=0){
				if(xx==1){
					if(xc!=bc){
						if(xa==ba){
							xx=0;
							ans+=xa;
							xa=0;
							ba=0;
						}else if(xa>ba){
							xx=1;
							xa=xa-ba;
							ans+=ba;
						}else{
							xx=0;
							ba-=xa;
							ans+=xa;
							xa=0;
						}
					}else{
						if(xa==ba){
							xx=0;
							xa=0;
							ba=0;
						}else if(xa>ba){
							xx=1;
							xa=xa-ba;
						}else{
							xx=0;
							ba-=xa;
							xa=0;
						}
					}
				}else if(xx==2){
					if(xc!=bc){
						if(xa==aa){
							xx=0;
							aa=0;
							ans+=xa;
							xa=0;
						}else if(xa>aa){
							xx=1;
							xa=xa-aa;
							ans+=aa;
						}else{
							xx=0;
							aa-=xa;
							ans+=xa;
							xa=0;
						}
					}else{
						if(xa==aa){
							xx=0;
							aa=0;
							xa=0;
						}else if(xa>aa){
							xx=2;
							xa=xa-aa;
							aa=0;
						}else{
							xx=0;
							aa-=xa;
							ans+=xa;
							xa=0;
						}
					}
				}
			}else{
				if(ac!=bc){
					if(aa==ba){
						ans+=aa;
						xa=0;
					}else if(aa>ba){
						xx=1;
						xa=aa-ba;
						xc=ac;
						ans+=ba;
					}else{
						xx=2;
						xa=ba-aa;
						xc=bc;
						ans+=aa;
					}
				}else{
					if(aa==ba){
						xa=0;
					}else if(aa>ba){
						xx=1;
						xa=aa-ba;
						xc=ac;
					}else{
						xx=2;
						xa=ba-aa;
						xc=bc;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
