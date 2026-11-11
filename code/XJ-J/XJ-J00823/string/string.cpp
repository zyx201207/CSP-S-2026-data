#include<bits/stdc++.h> 
using namespace std;
int n;
int a[200005];
char c[200005];
int x,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int x=1,y=n;
	while(x<y){
		if(c[x]!=c[y]){
			ans+=min(a[x],a[y]);
			if(a[x]<a[y]){
				x++;
				a[y]-=a[x-1];
			}
			else if(a[x]==a[y]){
				x++;
				y--;
			}
			else{
				y--;
				a[x]-=a[y+1];
			}
		}
		else{
			if(a[x]<a[y]){
				x++;
				a[y]-=a[x-1];
			}
			else if(a[x]==a[y]){
				x++;
				y--;
			}
			else{
				y--;
				a[x]-=a[y+1];
			}	
		}
	}
	cout<<ans<<endl;
	return 0;
}
