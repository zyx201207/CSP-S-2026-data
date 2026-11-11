#include<bits/stdc++.h>
using namespace std;
int n,a[201000];
char s[201000];
long long ans=0;
bool q,f=true;
string k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			k+=s[i];
		}
	}
	long long l=k.size(),r=0;
	long long mid=(l+r)/2;
	int cut;
	if(mid%2==0){
		for(long long i=1;i<=mid;i++){
			if(k[mid-i]==k[mid+i-1]){
				q=true;
			}else{
			    ans++;
				f=false;
			}
	    }
	}else{
		for(long long i=1;i<=mid;i++){
			if(k[mid-i]==k[i+mid]){
				q=true;
			}else{
			    ans++;
				f=false;
			}
		}
	}
	if(q&&f){
		cout<<"0";
		return 0;
	}
	cout<<ans;
	return 0;
}
