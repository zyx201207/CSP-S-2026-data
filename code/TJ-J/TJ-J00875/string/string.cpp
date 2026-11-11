#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans,cnt=0;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		ans+=a[i];
	}
	int l=1;
	int r=n;
	while(r>=l){
		long long h=a[l];
		while(h>0){
			if(s[r]==s[l]){
				int mi=min(a[r],h);
				a[r]-=mi;
				h-=mi;
				if(h>0) r--;
			}
			else{
				int mi=min(a[r],h);
				a[r]-=mi;
				cnt+=mi;
				h-=mi;
				if(h>0) r--;
			}
		}
		l++;
	}
	cout<<cnt;
	return 0;
} 
