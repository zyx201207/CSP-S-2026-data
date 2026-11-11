#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	cin>>n;
	int a[n];
	string b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;){
		for(int j=n-1;j>=0;){
			if(b[i]!=b[j]){
				m++;
				b[j]=b[i];
				a[i]--;
				a[j]--;
				if(a[i]==0) i++;
				if(a[j]==0) j--;
			}
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}