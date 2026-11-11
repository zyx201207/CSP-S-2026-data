#include<bits/stdc++.h>
using namespace std;
long long int n,a[200001][2],ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>c,a[i][1]=c;
	for(int i=1,j=n;i<=j;i++,j--){
		if(a[i][1]==a[j][1]){
			if(a[i][0]==a[j][0]) continue;
			else if(a[i][0]>a[j][0]) a[i][0]-=a[j][0],i--;
			else a[j][0]-=a[i][0],j++;
		}
		else{
			if(a[i][0]==a[j][0]) ans+=a[i][0];
			else if(a[i][0]>a[j][0]) a[i][0]-=a[j][0],ans+=a[j][0],i--;
			else a[j][0]-=a[i][0],ans+=a[i][0],j++;
		}
	}
	cout<<ans;
	return 0;
}
