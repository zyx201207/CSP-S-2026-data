#include<bits/stdc++.h>
using namespace std;
string s;
char a[200500];
long long n,t[200500],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>t[i]>>a[i];
	long long i=1,j=n;
	while(i<j){
		if(a[i]==a[j]){
			if(t[i]>=t[j]) t[i]-=t[j];
			else t[j]-=t[i];
		}
		else{
			if(t[i]>=t[j]){
				ans+=t[j];
				t[i]-=t[j];
			}
			else{
				ans+=t[i];
				t[j]-=t[i];
			}
		}
		if(t[i]==0&&t[j]==0) i++,j--;
		else if(t[i]>0) j--;
		else if(t[j]>0) i++;
	}
	cout<<ans<<'\n';
	return 0;
}
