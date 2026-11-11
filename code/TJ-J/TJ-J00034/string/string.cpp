#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,ans=0;
	string l[100007];
	cin>>n;
	if(n>2001){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			l[num]=c;
			num++;
		}
	}
	for(int i=0;i<num/2;i++){
		if(l[i]!=l[num-i-1]){
			ans++;
		}	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	/*for(int i=0;i<num;i++){
		cout<<l[i];
	}*/
	return 0;
}
