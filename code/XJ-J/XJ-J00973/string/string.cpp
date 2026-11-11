#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n];
	char b[n];
	for(int c=0;c<n;c+=1){
		scanf("%d",&a[c]);
		cin>>b[c];
	}
	string d;
	int g=0,count=0;
	for(int e=0;e<n;e+=1){
		for(int f=0;f<a[e];f+=1) d+=b[e];
		g+=a[e];
	}
	for(int h=0;h<g/2;h+=1){
		if(d[h]!=d[g-h-1]) count+=1;
	}
	printf("%d",count);
	fclose(stdin);
	fclose(stdout);
	return 0;
}