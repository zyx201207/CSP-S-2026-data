//SN-J00756 程谟然 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long a[N+5];
char c[N+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long corn=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		corn+=a[i];
	}
	string s="";
	long long ad=1;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s[ad]=c[i];
			ad++;
		}
	}
	long long swa=0;
	for(long long i=1;i<=corn/2;i++){
		if(s[i]!=s[corn+1-i]){
			swa++;
		}
	}
	cout<<swa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
