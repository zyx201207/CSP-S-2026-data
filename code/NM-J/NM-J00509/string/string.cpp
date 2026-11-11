#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10;
struct node{
	long long mr;
	char a;
}marui[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long minn=0;
	for(int i=1;i<=n;i++){
		cin>>marui[i].mr>>marui[i].a;
		minn=max(minn,marui[i].mr);
	}
	if(n<=2000&&minn<=10000){
		string s;
		int x=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=marui[i].mr;j++){
				s[++x]=marui[i].a;
			}
		}
		int ans=0;
		for(int i=0,j=x;i<=x,j>=i;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}	
		}
		cout<<ans;
	}
	else{
		int i=1,j=n;
		int ans=0;
		while(i<=n&&j>=1){
			if(marui[i].mr>marui[j].mr){
				if(marui[i].a==marui[j].a){
					marui[i].mr=marui[i].mr-marui[j].mr;
					marui[j].mr=0;
					j--;
				}
				else{
					ans=ans+marui[j].mr;
					marui[i].mr-=marui[j].mr;
					marui[j].mr=0;
					j--;
				}
			}
			else if(marui[i].mr<marui[j].mr){
				if(marui[i].a==marui[j].a){
					marui[j].mr=marui[j].mr-marui[i].mr;
					marui[i].mr=0;
					j++;
				}
				else{
					ans=ans+marui[i].mr;
					marui[j].mr-=ans;
					marui[i].mr=0;
					i--;
				}
			}
			else{
				if(marui[i].a==marui[j].a){
					marui[i].mr=0;
					marui[j].mr=0;
					i++;
					j--;
				}
				else{
					ans+=marui[i].mr;
					marui[i].mr=0;
					marui[j].mr=0;
					i++;
					j--;
				}
			}
			if(i==j){
				break;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
