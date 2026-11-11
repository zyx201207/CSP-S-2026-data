#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a=0,b=0,c=0;
	cin>>a>>b;
	long long d[a]={0};
	for(int i=0;i<a;i++){
		cin>>d[i];
	}
	if(b==1){
		for(int i=0;i<a;i++){
			if(c<d[i]){
				c=d[i];
			}
		}
		cout<<c<<endl;
		return 0;
	}
	if(a==b){
		c=d[0];
		for(int i=0;i<a;i++){
			c=(c & d[i]);
		}
		cout<<c<<endl;
		return 0;
	}
	long long s=0;
	if(a==b-1){
		c=d[0];
		for(int i=0;i<a;i++){
			for(int j=0;j<a;i++){
				if(j!=i)c=(c & d[i]);
			}
			if(c>s)s=c;
		}
		cout<<s<<endl;
		return 0;
	}
	if(b==2){
		for(int i=0;i<a;i++){
			for(int j=i+1;j<a;j++){
				if((d[i] & d[j])>c){
					c=(d[i] & d[j]);
				}
			}
		}
		cout<<c<<endl;
		return 0;
	}
	long long  df=0,er=0;
	for(int i=0;i<a;i++){
		df=0;
		for(int j=0;j<a-1;j++){
			if(d[j]<d[j+1]){
				swap(d[j],d[j+1]);
			}
		}
	}
	cout<<d[b-1];
	return 0;
}