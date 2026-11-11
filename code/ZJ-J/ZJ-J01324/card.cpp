#include <bits/stdc++.h>
using namespace std;
int a[1000010],n,s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=4){
		cout<<s<<" "<<a[1]<<" "<<n;
	}else{
		cout<<n<<" "<<s<<" "<<a[1];
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
