#include<bits/stdc++.h>
using namespace std;

const int N=200010;
char q[N]={};
char qw[N]={}; 
long long a[N]={};
char c[N]={};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int num=0; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i];j++){
			qw[i]=c[i];
		}
	}
	for(int i=0;i<n;i++){
		cout<<qw[i];
	}
	int TF=0;
	long long u=0;
	for(int i=0;i<n;i++){
		if(c[i]!=q[i]){
			u++;
		}
	}
	cout<<u/2;
	return 0;
}
