#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub5.in","r",stdin);
	freopen("hub5.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		t--;
		int n,k,ans;
		cin>>n>>k;
		/*
		for(int i=1;i<=n;i++){
			int a,b;
			cin>>a>>b;
		}*/
		int l=n/2;
		k=k/2+1;
		
		if(((n%2)&&(k%2))||(!(n%2)&&!(k%2))) int ans=l/k-1;
		else ans=l/k;
		printf("%d\n",ans);
	}
	return 0;
}
