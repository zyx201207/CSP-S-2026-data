#include<bits/stdc++.h>
using namespace std;
string a;
long long n,c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		string x;
		int e;
		cin>>e>>x;
		for(int i=0;i<e;i++){
			c++;
			a+=x;
		}
	}
	for(int i=1;i<=c/2;i++){
		for(int j=c;j>=c;j--){
			if(a[i]!=a[j]){
				s++;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}