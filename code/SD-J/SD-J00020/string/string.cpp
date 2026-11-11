#include<bits/stdc++.h>
using namespace std;
char m[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=1,longg=0;;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		longg+=a;
		for(int j=1;j<=a;j++){
			m[cnt]=b;
			cnt++;
		}
	}
	cnt--;
	//cout<<cnt;
	int h=longg/2,ans=0;
	for(int i=1;i<=h;i++){
		//cout<<m[i]<<m[cnt+1-i]<<endl;
		if(m[i]!=m[cnt+1-i]){
			//cout<<1;
			ans++;
		}
		//else cout<<0;
	}
	//for(int j=1;j<=5;j++){
	//	cout<<m[j];
	//}
	cout<<ans;
	return 0;
} 
