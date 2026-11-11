#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//我献祭林老师一亿根头发换AC
	//我献祭周扬合一万根头发换AC
	//我献祭GH一米身高换AC
	//CSP为什么不帮考生处理好数据?
	//因为他很CS 
	int n;
	cin>>n;
	long long a[n+1];
	char s[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long ans=0;
	int x=1,y=n;
	while(x<y){
		if(s[x]==s[y]){
			if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}else if(a[x]<a[y]){
				a[y]-=a[x];
				x++;
			}else{
				x++;
				y--;
			}
		}else{
			if(a[x]>a[y]){
				ans+=a[y];
				a[x]-=a[y];
				y--;
			}else if(a[x]<a[y]){
				ans+=a[x];
				a[y]-=a[x];
				x++;
			}else{
				ans+=a[x];
				x++;
				y--;
			}
		}
	}
	cout<<ans;
	return 0;
}
