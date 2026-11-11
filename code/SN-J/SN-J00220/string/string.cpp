#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,f=0,ans;
	cin>>a;
	int b[100000];
	for(int i=0;i<=a;i++){
		int c,e=0;
		char d;
		cin>>c>>d;
		 f+=c;
		for(int j=0;j<=c;j++){
			b[e]==d;
			e++;
		}
	}

	for(int j=0;j<=f/2;j++){
			if(b[j]!=b[f-j-1])
			ans++;
		}
		cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
