#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
long long m;
char a;
char arr[2000000];
int j=0;
cin>>n;
for(int i=0;i<n;i++){
	cin>>m>>a;
	for(int j1=0;j1<m;j++,j1++){
		arr[j]=a;
	}
}
int s=0;
for(int i=0;i<j/2;i++){
	if(arr[i]!=arr[j-1-i]){
		s++;
	}
}
cout<<s;
return 0;
} 
