#include<bits/stdc++.h>
using namespace std;
long long int n,h1,h1n,h2,h2n;
long long int s=0;
long long int a[200099];
char b[200099];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	//cout<<"OK\n";
	h1=1;
	h2=n;
	h1n=a[h1];
	h2n=a[h2];
	//cout<<"?\n";
	while(h1<h2){
		//cout<<"OK\n";
		//cout<<"?\n"<<h1<<" "<<h2<<endl;
		if(b[h1]==b[h2]){
			//cout<<"A\n"<<(h1n==h2n)<<endl;
			if(h1n==h2n){
				//cout<<"A1\n";
				h1+=1;
				h2-=1;
				h1n=a[h1],h2n=a[h2];
			}else if(h1n<h2n){
				//cout<<"A2\n";
				h2n-=h1n;
				h1++;
				h1n=a[h1];
			}else{
				//cout<<"A3\n";
				h1n-=h2n;
				h2--;
				h2n=a[h2];
			}
			//cout<<s<<endl;
		}else{
			//cout<<"B\n";
			if(h1n==h2n){
				s+=h1n;
				h1+=1;
				h2-=1;
				h1n=a[h1],h2n=a[h2];
			}else if(h1n<h2n){
				s+=h1n;
				h2n-=h1n;
				h1++;
				h1n=a[h1];
			}else{
				s+=h2n;
				h1n-=h2n;
				h2--;
				h2n=a[h2];
			}
			//cout<<s<<endl;
		}
	}
	cout<<s;
	return 0;
}
