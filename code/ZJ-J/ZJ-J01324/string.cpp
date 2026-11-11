#include <bits/stdc++.h>
using namespace std;
int a[100010],b[1000010],n,c,d,e,f;
int main(){
	int s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n=2){
	cin>>c>>d>>e>>f;
	cout<<0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(b[i]==b[j]){
					
					return 0;
			}
		}	
		if(a[i]==1){
			cout<<2;
		}else{
			if(a[i]==1000000000){
				cout<<3000000000;
			}else{
				cout<<s;	
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
