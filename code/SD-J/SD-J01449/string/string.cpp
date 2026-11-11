#include<iostream>
#include<string>
using namespace std;
const int N=2e5+20;
string k;
long long n,a[N],ans,t,sum,y;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		while(a[i]!=0){
			k=k+s[i];
			a[i]--;
		}
	}
	for (int i=0;i<(k.size()+1/2);i++){			
//		cout<<k[k.size()-i-1]<<" "<<k[i]<<"\n";
		if(k[k.size()-i-1]!=k[i]){
			k[k.size()-i-1]=k[i];
			ans++;
		}
	}
	cout<<ans;
//	for (int i=0;i<k.size();i++){
//		cout<<k[i];
//	}
	return 0;
} 
