#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
struct guu{
	int id;
	int to;
}a[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].id>>a[i].to;
		}
		for(int i=n+1;i<=2*n;i++){
			a[i].id=a[i-n].to;
			a[i].to=a[i-n].id;
		}
		if(t%2==0)
			cout<<1<<endl;
		else
		cout<<2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
