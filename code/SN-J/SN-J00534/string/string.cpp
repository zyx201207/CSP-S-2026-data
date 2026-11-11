#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define int long long
int n,ans,s[200050];
struct p{
	int c;
	string ss;
}a[200050];
#define int int 
int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	#define int long long
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].ss;
		s[i]=s[i-1]+a[i].c;
	} 
	int d=s[n];
	if(d>=1000000000){
		int i=1;
		while(1){
			if(s[i]>d/2){
				for(int j=1;j<=i-1;j++){
					if(a[j].ss==a[n-j+1].ss) continue;
					else ans+=a[j].c;
				}
				break;
			}
			i++;
		}
		cout<<ans;
		return 0;
	}
	ans=0;
	string s1="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].c;j++) s1+=a[i].ss;
	}
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
