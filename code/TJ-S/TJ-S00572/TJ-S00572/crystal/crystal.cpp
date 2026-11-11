#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	int c[a];int q[a],w=a;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	int d,x;
	for(int i=0;i<a;i++){
		if(i==0)x=c[i];
		if(i==a)d=c[i];
	}
	cout<<d<<x;
	int g;
	g=(d-x)/2;
	cout<<g;
	for(int i=0;i<a;i++){
		if(c[i]==g){
			g=i;
			break;
		}
	}
	int ans=0;
	for(int i=g;i>=0;i--){
		if(c[g]-c[i]<=b){
			c[i]=c[g];
			b=b-c[g]+c[i];
			ans+=1;
		}
		else{
			break;
		}
	}
	cout<<ans;
}

