#include<bits/stdc++.h>
using namespace std;
long long  n,a[200010];
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		for(int j=ans;j<ans+a[i];j++){
		    s[j]=b;
	    }
	    ans+=a[i];	
	}
	
	int num=0;
	if(ans%2==0){
		int mid=ans/2;
		for(int i=mid;i>=0;i--){
			if(s[i]!=s[ans-i+1]) num++;
		}
	}
	else{
		int mid=ans/2+1;
		for(int i=mid;i>=0;i--){
			if(s[i]!=s[ans-mid+1]) num++;
		}
	}
	cout<<num;
	return 0;
}
