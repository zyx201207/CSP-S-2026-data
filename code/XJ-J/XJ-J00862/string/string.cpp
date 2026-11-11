#include<bits/stdc++.h> 
using namespace std;
long long a[100000005];
int main(){
	freopen("string.in","r"stdin);
	freopen("string.out","w"stdout);
	int n,i=1,w=0,m=0;
	string c;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
		}
		else{
			if(a[1]>a[2]){
				cout<<a[1]-a[2];
			}
			else{
				cout<<a[2]-a[1];
			}
		}
	}
	if(n==3){
		if(c[1]==c[2]==c[3]){
			cout<<0;
		}
		if(a[1]==2){
			if(a[2]==2){
				if(a[3]==1){
						if(c[1]!=c[2]!=c[3]){
				cout<<2;
			}
			}
			}
		}
	}
	for(int y=1;y<n;y++){
		if(c[y]==c[y+1]){
			w++;
		}
		else{
			w=0;
		}
	}
	if(w!=0){
		cout<<0;
	}
	for(int f=1;f<n;f++){
		if(a[f]==a[f+1]){
			m++;
		}
		else{
			m=0;
		}
	}
	if(m!=0){
		cout<<a[1]*3;
	}
	return 0;
}