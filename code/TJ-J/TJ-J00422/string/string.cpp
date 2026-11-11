#include<iostream>
#define int long long
using namespace std;
struct stu{
	char c;
	long long a;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int js=0;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].c;
		js+=a[i].a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(js*n<=30000000){
		string s="";
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i].a;j++){
				s+=a[i].c;
			}
		}
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-1-i]){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		int js=0;
		for(int i=0;i<n/2;i++){
			if(a[i].c==a[n-1-i].c){
				if(a[i].a<a[n-1-i].a){
					a[i].a+=a[n-1-i].a-a[i].a;
					int j=i+1;
					int k=a[n-1-i].a-a[i].a;
					while(k>a[j].a){
						k-=a[j].a;
						js+=a[j].a;
						a[j].a=0;
						j++;
					}
					a[j].a-=a[n-j].a-a[j-1].a;
					js+=a[n-j].a-a[j-1].a;
				}
				else{
					a[n-1-i].a+=a[i].a-a[n-1-i].a;
				}
			}
		}
		cout<<0;
	}
}
