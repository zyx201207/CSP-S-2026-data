#include<bits\stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len=1;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[len],&b[len]);
		if(b[len]==b[len-1]){
			a[len-1]+=a[len];
			a[len]=0;
			b[len]=' ';
			len--;
		}
		len++;
	}
	len--;
	int llll=1,rrrr=len;
	while(llll<rrrr){
		if(b[llll]!=b[rrrr]){
			if(a[llll]>a[rrrr]){
				a[llll]-=a[rrrr];
				ans+=a[rrrr]; 
				rrrr--;
			}
			else if(a[llll]==a[rrrr]){
				ans+=a[rrrr]; 
				llll++;
				rrrr--;
			}
			else{
				ans+=a[llll]; 
				a[rrrr]-=a[llll];
				llll++;
			}
		}
		else{
			if(a[llll]>a[rrrr]){
				a[llll]-=a[rrrr];
				rrrr--;
			}
			else if(a[llll]==a[rrrr]){
				llll++;
				rrrr--;
			}
			else{
				a[rrrr]-=a[llll];
				llll++;
			}
		}
	}
	cout<<ans;
	return 0;
}
