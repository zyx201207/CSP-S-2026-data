#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,m=0;
cin>>n;
int a[10000];
char b[10000];
string k;
for(int i=0;i<n;i++){
	cin>>a[i];
	cin>>b[i];
}
int o=0;
for(int i=0,l=0;i<n;i+=a[i]){
	k=k+b[i];
}
for(int i=0,j=k.size()-1;i<k.size()-1,j>=0;i++,j--){
	if(k[i]!=k[j]){
		m++;
	}
}
cout<<m;


fclose(stdin);
fclose(stdout);
return 0;
    }
