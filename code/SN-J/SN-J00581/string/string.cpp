#include<bits/stdc++.h>
using namespace std;
int main(){
  	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[900010];
	int n;
	cin>>n;
	long long b;
	char c;
	long long d=1,w=0;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		w+=b;
		for(int i=d;i<=w;i++){
			a[i]=c;
		}
		d+=b;
	}
	bool flag=false;
	int q=0;
	for(int i=1;i<=w;i++){
		int j=w;
		if(a[j]==a[i]&&j>=1){
			flag=true;
		}else if(a[i]!=a[j]&&j>=1){
			q++;
			flag=false;
		}
		j--;
	}
	if(flag){
		cout<<0;
		return 0;
	}else{
		cout<<q/2;
	}
	return 0;
} 
