#include<bits/stdc++.h>
using namespace std;
long long a[200000];
char c[200000];
char b[10000000000];
int main(){
	freopen("stringin","r",stdin);
	freopen("stringout","w",stdout);
	int n,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=l+1;j<=l+a[i];j++){
			b[j]=c[i];
		}
		l+=a[i];
	}
	int sum=0;
	for(int i=1;i<=l/2;i++){
		if(b[i]!=b[l-i]){
			sum+=1;
		}
	}
	cout<<sum; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

