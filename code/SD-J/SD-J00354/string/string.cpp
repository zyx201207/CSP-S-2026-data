#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long num[N],n;char c[N];
bool vis[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans=0;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
		len+=num[i];
	}
	if(len<=100000){
		string s="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=num[i];j++){
				s+=c[i];
			}
		} 
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}else{
		for(int l=1;l<=n;l++){
			if(vis[l]) continue;
			long long sum=0;
			for(int r=n;r>l;r--){
				sum+=num[r];
				if(sum>=num[l]){
					if(c[r]!=c[l]) ans+=num[l];
					num[r]=sum-num[l];
					break;
				}
				vis[r]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

