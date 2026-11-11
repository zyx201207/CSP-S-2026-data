#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans;
struct edge{
	int len;
	char zf;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		int s;
		char c;
		cin>>s>>c;
		a[i].len=s;
		a[i].zf=c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].zf!=a[r].zf){
			if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				ans+=a[l].len;
				l++;
			}else if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				ans+=a[r].len;
				r--;
			}else if(a[l].len==a[r].len){
				ans+=a[l].len;
				l++;
				r--;
			}
		}else{
			if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				l++;
			}else if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				r--;
			}else if(a[l].len==a[r].len){
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
