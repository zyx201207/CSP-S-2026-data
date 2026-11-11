#include<bits/stdc++.h>
using namespace std;
int a[2000000];
char c[2000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	int bu=0;
	bool bo=true;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		char c2=c[i];
		if(c[i]!=c2){
			bo=false;
		}
	}
	string s,s2,s3;
	int ant=0;
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=a[i];j++){
			ant++;
			s[ant]=c[i];
		}
	}
	cout<<sum/2;
	return 0;
}
