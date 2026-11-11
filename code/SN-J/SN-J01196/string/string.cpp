#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);//记得注释回来 
	freopen("string.out","w",stdout);
	int n,num=0;
	cin>>n;
	int a;
	char c[1005];
	for(int i=1;i<=n;i++){
		cin>>a>>c[i];
		if(c[i]==c[i+1]){
			num++;
		}
	} 
	if(num==n){
		cout<<0;
		return 0;
	}
	return 0;
}
