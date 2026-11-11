#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,cnt=0,num,p[N];
string b;
string a;
int m,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i]>>a[i];
		h+=p[i];
		if(i==0){
			m=p[i];
		}else{
			m=m+m-1;
		}
		for(int j=num;j<=m;j++){
			b[j]=a[i];
		}
		num=num+p[i];
	}
	for(int i=0;i<=h-1;i++){
		if(b[i]!=b[h-1-i]){
			cnt++;
			if(i==h-1-i){
				cout<<cnt;
				return 0;
			}else if(i>=h/2){
				cout<<cnt-1;
				return 0;
			}
		}
	}
	return 0;
} 
