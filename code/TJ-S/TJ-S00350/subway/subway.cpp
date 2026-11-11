#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s[10000],a,z[10000],lt,bu,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		
	}
	
	for(int i=1;i<=m;i++){
		lt=s[i]+1;
		if(s[i+1]==lt){
			lt+=s[i+1];
			bu++;
		}
	}
	bu++;
	cout<<bu;
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	return 0;
}
