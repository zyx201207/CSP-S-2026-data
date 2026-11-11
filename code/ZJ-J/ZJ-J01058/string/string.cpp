#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
char a[N];
long long len[N],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i];
		cin>>a[i];
	}
	int x=1,y=n;
	while(x<y){
		if(a[x]==a[y]){
			if(len[x]==len[y]){
				x++;y--;
			}else if(len[x]>len[y]){
				len[x]-=len[y];
				y--;
			}else{
				len[y]-=len[x];
				x++;
			}
		}else{
			if(len[x]==len[y]){
				ans+=len[x];
				x++;y--;
			}else if(len[x]>len[y]){
				len[x]-=len[y];
				ans+=len[y];
				y--;
			}else{
				len[y]-=len[x];
				ans+=len[x];
				x++;
			}
		}
	}
	cout<<ans;
	return 0;
}
