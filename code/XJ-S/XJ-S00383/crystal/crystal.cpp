#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int e=1;
int a[100010],b[100010],c[100010],an[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n-1;i++){
			if(a[i+1]<a[i]){
				b[i]=a[i];
				a[i]=a[i+1];
				a[i+1]=b[i];	
			}
		}
	}
	for(int i=0;i<n-1;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int j=0;j<n-1;j++){
		for(int i=0;i<e;i++){
			x+=c[i];
		}
		an[j]=x;
		x=0;
		e++;
	}
	for(int j=0;j<n-1;j++){
		for(int i=0;i<n-2;i++){
			if(an[i+1]<an[i]){
				b[i]=an[i];
				an[i]=an[i+1];
				an[i+1]=b[i];	
			}
		}
	}
	if(an[0]>m){
		cout<<"0";
	}else{
		for(int i=0;i<n-1;i++){
			if(m-an[i]<0){
				cout<<i+1;
				break;
			}	
		}
	}

	
	return 0;	
} 
