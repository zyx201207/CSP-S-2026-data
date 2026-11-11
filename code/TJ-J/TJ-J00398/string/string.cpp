#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0,cnt=-1,t=0;
	cin>>n;
	char l[1000005],c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			l[cnt]=c;
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(l[cnt/2-i]!=l[i]){
			l[cnt/2-i]=l[i];
			ans++;	
		}
	}
	cout<<ans;
	return 0;
}      
