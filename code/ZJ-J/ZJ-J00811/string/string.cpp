#include<iostream>
#include<string>
using std::iostream;
using std::string;
using std::cin;
using std::cout;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=0;
	long long ma,s;
	cin>>n;
	int a[n+3]={};
	char b[n+3];
	string w,v;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ma+=a[i];
	}
	s=(ma+1)/2;
	int m=n;
	for(int i=1;i<=s-1;i++){
		v=v+b[i];
	}
	for(int i=s+1;i<=ma;i++){
		w=w+b[i];
	}
	if(v==w){
		cout<<0;
	}
	else{	
		for(int i=1;i<=n;i++){
			if(v[i]!=w[i]){
				x++;
			}
		}
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
