#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,d=1,x=0;
	char c,b[100005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=d;j<=a;j++){
			b[j]=c;
		}
		d+=a;
	}
	d--;
	if(d%2==0){
		for(int i=1;i<=d/2;i++){
			if(b[i]!=b[d-i+1])
				x++;
		}
	}
	else{
		for(int i=1;i<=(d-1)/2;i++){
			if(b[i]!=b[d-i+1])
				x++;
		}
	}
	cout<<x;
	return 0;
}