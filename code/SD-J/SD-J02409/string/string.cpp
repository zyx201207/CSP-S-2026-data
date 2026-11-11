#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int tmp1=((n&1)?(ceil(n/2)):n/2),tmp2=n;
	int a[(int)1e5+10];
	char ch[(int)1e5+10];
	while(n-->=tmp1){
		cin>>a[n-tmp1]>>ch[n-tmp1];
	}
	int ar[(int)1e5+10];char chr[(int)1e5+10];
	while(n-->0){
		cin>>ar[n]>>chr[n];
	}
	for(int i=tmp2;i>tmp1;i--){
		if(chr[i-1]!=ch[tmp2-i-tmp1]){
			ans+=max(ar[i-1],a[tmp2-i-tmp1]);
			if(ar[i-1]>a[tmp2-i-tmp1]){
				a[tmp2-i-tmp1-1]=ar[i-1]-a[tmp2-i-tmp1];
			}
			else{
				ar[i-2]=a[tmp2-i-tmp1]-ar[i-1];
			}
		}
		if(ar[i-1]<a[tmp2-i-tmp1]&&chr[i]==ch[tmp2-i-tmp1]){
			if(chr[i]==chr[i-1]){
				ar[i]-=(a[tmp2-i-tmp1]-ar[i-1]);
				continue;
			}
			else{
				ans+=a[tmp2-i-tmp1]-ar[i-1];
				cout<<ans<<'\n';
			}
		}
		if(ar[i-1]>a[tmp2-i-tmp1]&&chr[i-1]==ch[tmp2-i-tmp1]){
			if(ch[i+1]==ch[i]){
				a[i+1]-=(a[tmp2-i-tmp1]-ar[i-1]);
				continue;
			}
			else{
				ans+=ar[i-1]-a[tmp2-i-tmp1];
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
